#!/usr/bin/env python

import clang.cindex
import sys
import os
import logging
import argparse
import fnmatch
import json
import jsonpickle
import re

from generator import *
from converter.util import CacheUtil

if os.name == "nt":
    clang.cindex.Config.set_library_file('../bin/libclang.dll')

if os.name == "posix":
    clang.cindex.Config.set_library_file('../bin/libclang.so')

index = clang.cindex.Index.create()
webidlGenerator = WebIdlGenerator()


def findFilesInDir(rootDir, patterns):
    """ Searches for files in rootDir which file names mathes the given pattern. Returns
    a list of file paths of found files"""
    foundFiles = []
    for root, dirs, files in os.walk(rootDir):
        for p in patterns:
            for filename in fnmatch.filter(files, p):
                foundFiles.append(os.path.join(root, filename))
    return foundFiles


def parseClassConstructor(cursor):
    constructor = UmlConstructor()
    constructor.name = cursor.spelling or cursor.displayname
    constructor.node = cursor
    return constructor


def processClassField(cursor):
    """ Returns the name and the type of the given class field.
    The cursor must be of kind CursorKind.FIELD_DECL"""
    type = None
    fieldChilds = list(cursor.get_children())
    if len(fieldChilds) == 0:  # if there are not cursorchildren, the type is some primitive datatype
        type = cursor.type.spelling
    else:  # if there are cursorchildren, the type is some non-primitive datatype (a class or class template)
        for cc in fieldChilds:
            if cc.kind == clang.cindex.CursorKind.TEMPLATE_REF:
                type = cc.spelling
            elif cc.kind == clang.cindex.CursorKind.TYPE_REF:
                type = cursor.type.spelling
    name = cursor.spelling
    return name, type


def processClassMethod(cursor):
    if cursor.kind == clang.cindex.CursorKind.FUNCTION_TEMPLATE:
        # todo templates
        return None
    if cursor.kind == clang.cindex.CursorKind.CXX_METHOD:
        method = UmlMethod()
        method.name = cursor.spelling or cursor.displayname

        method.node = cursor

        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.PARM_DECL:
                method.params.append(processClassMethodParam(method, c))
            if c.kind == clang.cindex.CursorKind.TYPE_REF:
                # todo
                processClassMethodType(method, c)

        method.returnType = processType(method, cursor, cursor.result_type)

        filter(None, method.params)

        returnType, argumentTypes = cursor.type.spelling.split(' ', 1)

        return returnType, cursor.spelling, method

def processClassMethodParam(method, cursor):
    if cursor.kind == clang.cindex.CursorKind.PARM_DECL:
        text = cursor.spelling or cursor.displayname
        kind = str(cursor.kind)[str(cursor.kind).index('.') + 1:]

        method_param = UmlMethodParam()
        method_param.name = text
        method_param.node = cursor
        method_param.kind = kind
        method_param.type = processType(method, cursor, cursor.type)
        return method_param


def processClassMethodType(menthod, cursor):
    # print "skipped part {}".format(cursor.kind)
    return None


def processType(method, cursor, type):
    result = UmlMethodType()
    result.name = cursor.spelling
    result.node = cursor
    result.type = type
    return result


def processClassMemberDeclaration(umlClass, cursor):
    """ Processes a cursor corresponding to a class member declaration and
    appends the extracted information to the given umlClass """
    if cursor.kind == clang.cindex.CursorKind.CONSTRUCTOR:
        umlClass.constructors.append(parseClassConstructor(cursor))
    if cursor.kind == clang.cindex.CursorKind.CXX_BASE_SPECIFIER:
        for baseClass in cursor.get_children():
            if baseClass.kind == clang.cindex.CursorKind.TEMPLATE_REF:
                umlClass.parents.append(baseClass.spelling)
            elif baseClass.kind == clang.cindex.CursorKind.TYPE_REF:
                umlClass.parents.append(baseClass.type.spelling)
    elif cursor.kind == clang.cindex.CursorKind.FIELD_DECL:  # non static data member
        name, type = processClassField(cursor)
        if name is not None and type is not None:
            # clang < 3.5: needs patched cindex.py to have
            # clang.cindex.AccessSpecifier available:
            # https://gitorious.org/clang-mirror/clang-mirror/commit/e3d4e7c9a45ed9ad4645e4dc9f4d3b4109389cb7
            if cursor.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
                umlClass.publicFields.append((name, type))
            elif cursor.access_specifier == clang.cindex.AccessSpecifier.PRIVATE:
                umlClass.privateFields.append((name, type))
            elif cursor.access_specifier == clang.cindex.AccessSpecifier.PROTECTED:
                umlClass.protectedFields.append((name, type))
    elif cursor.kind == clang.cindex.CursorKind.CXX_METHOD:
        try:
            returnType, argumentTypes = cursor.type.spelling.split(' ', 1)
            if cursor.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
                umlClass.publicMethods.append(processClassMethod(cursor))
            elif cursor.access_specifier == clang.cindex.AccessSpecifier.PRIVATE:
                umlClass.privateMethods.append(
                    (returnType, cursor.spelling, argumentTypes)
                )
            elif cursor.access_specifier == clang.cindex.AccessSpecifier.PROTECTED:
                umlClass.protectedMethods.append(
                    (returnType, cursor.spelling, argumentTypes)
                )
        except:
            logging.error("Invalid CXX_METHOD declaration! " + str(cursor.type.spelling))
    elif cursor.kind == clang.cindex.CursorKind.FUNCTION_TEMPLATE:
        returnType, argumentTypes = cursor.type.spelling.split(' ', 1)
        if cursor.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
            umlClass.publicMethods.append(processClassMethod(cursor))
        elif cursor.access_specifier == clang.cindex.AccessSpecifier.PRIVATE:
            umlClass.privateMethods.append((returnType, cursor.spelling, argumentTypes))
        elif cursor.access_specifier == clang.cindex.AccessSpecifier.PROTECTED:
            umlClass.protectedMethods.append((returnType, cursor.spelling, argumentTypes))


def processClass(cursor, inclusionConfig):
    """ Processes an ast node that is a class. """
    umlClass = UmlClass()  # umlClass is the datastructure for the DotGenerator

    umlClass.node = cursor

    # that stores the necessary information about a single class.
    # We extract this information from the clang ast hereafter ...
    if cursor.kind == clang.cindex.CursorKind.CLASS_TEMPLATE:
        # process declarations like:
        #   template <typename T> class MyClass
        umlClass.fqn = cursor.spelling
    else:
        # process declarations like:
        #   class MyClass ...
        #   struct MyStruct ...
        umlClass.fqn = cursor.type.spelling  # the fully qualified name

    import re
    if (inclusionConfig['excludeClasses'] and
            re.match(inclusionConfig['excludeClasses'], umlClass.fqn)):
        return

    if (inclusionConfig['includeClasses'] and not
    re.match(inclusionConfig['includeClasses'], umlClass.fqn)):
        return

    for c in cursor.get_children():
        # process member variables and methods declarations
        processClassMemberDeclaration(umlClass, c)

    webidlGenerator.addClass(umlClass)


def traverseAst(cursor, inclusionConfig):
    if (cursor.kind == clang.cindex.CursorKind.CLASS_DECL
        or cursor.kind == clang.cindex.CursorKind.STRUCT_DECL
        or cursor.kind == clang.cindex.CursorKind.CLASS_TEMPLATE):
        # if the current cursor is a class, class template or struct declaration,
        # we process it further ...
        processClass(cursor, inclusionConfig)
    for child_node in cursor.get_children():
        traverseAst(child_node, inclusionConfig)


def parseTranslationUnit(filePath, includeDirs, inclusionConfig):
    clangArgs = ['-x', 'c++'] + ['-I' + includeDir for includeDir in includeDirs]
    tu = index.parse(filePath, args=clangArgs, options=clang.cindex.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES)
    for diagnostic in tu.diagnostics:
        logging.debug(diagnostic)
    logging.info('Translation unit:' + tu.spelling + "\n")
    traverseAst(tu.cursor, inclusionConfig)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="CodeDependencyVisualizer (CDV)")
    parser.add_argument('-d', required=True, help="directory with source files to parse (searches recusively)")
    parser.add_argument('-o', '--outFile', default='engineSim.idl',
                        help="output file name / name of generated dot file")
    parser.add_argument('-gw', '--glueWrapperFile', default='my_glue_wrapper.cpp',
                        help="name of the glue wrapper file")
    parser.add_argument('-root', help="root path for all source manipulations")
    parser.add_argument('-u', '--withUnusedHeaders', help="parse unused header files (slow)")
    parser.add_argument('-a', '--associations', action="store_true", help="draw class member assiciations")
    parser.add_argument('-i', '--inheritances', action="store_true", help="draw class inheritances")
    parser.add_argument('-p', '--privMembers', action="store_true", help="show private members")
    parser.add_argument('-t', '--protMembers', action="store_true", help="show protected members")
    parser.add_argument('-P', '--pubMembers', action="store_true", help="show public members")
    parser.add_argument('-I', '--includeDirs', help="additional search path(s) for include files (seperated by space)",
                        nargs='+')
    parser.add_argument('-v', '--verbose', action="store_true", help="print verbose information for debugging purposes")
    parser.add_argument('--excludeClasses', help="classes matching this pattern will be excluded")
    parser.add_argument('--includeClasses', help="only classes matching this pattern will be included")

    args = vars(parser.parse_args(sys.argv[1:]))

    # filesToParsePatterns = ['*.cpp', '*.cxx', '*.c', '*.cc']
    # if args['withUnusedHeaders']:
    #    filesToParsePatterns += ['*.h', '*.hxx', '*.hpp']

    filesToParsePatterns = ['*.h']

    filesToParse = []
    for i in args['d'].split(","):
        filesToParse += findFilesInDir(i, filesToParsePatterns)

    #pat = re.compile("GameSetup")
    #filesToParse = filter(lambda file: re.search(pat, file), filesToParse)

    # subdirectories = [x[0] for x in os.walk(args['d'])]

    loggingFormat = "%(levelname)s - %(module)s: %(message)s"
    logging.basicConfig(format=loggingFormat, level=logging.INFO)
    if args['verbose']:
        logging.basicConfig(format=loggingFormat, level=logging.DEBUG)

    logging.info("found " + str(len(filesToParse)) + " source files.")

    for sourceFile in filesToParse:
        logging.info("parsing file " + sourceFile)
        parseTranslationUnit(sourceFile, args['includeDirs'], {
            'excludeClasses': args['excludeClasses'],
            'includeClasses': args['includeClasses']})

    webidlFileName = args['outFile']
    logging.info("generating webidlfile " + webidlFileName)

    jsonpickle.set_encoder_options('simplejson', indent=4)

    generator_result = webidlGenerator.generate()

    with open(webidlFileName, 'w') as webidlFile:
        webidlFile.write(generator_result[0])
        webidlFile.write("/* --- Type cache ---\n{}\n */"
                         .format(json.dumps(json.loads(jsonpickle.encode(CacheUtil.type_cache)), indent=4)))

        webidlFile.write("/* --- Source files ---\n{}\n */"
                         .format(json.dumps(json.loads(jsonpickle.encode(CacheUtil.source_files)), indent=4)))

    glueWrapperFileName = args['glueWrapperFile']
    logging.info("generating glueWrapperFile " + glueWrapperFileName)

    with open(glueWrapperFileName, 'w') as glueWrapperFile:
        tpl = Template(filename='bind_glue_wrapper.mako')
        rendered = tpl.render(
            sources=CacheUtil.get_wrapper_includes_list(os.path.abspath(args['root']), generator_result[1])
        )

        glueWrapperFile.write(rendered)
