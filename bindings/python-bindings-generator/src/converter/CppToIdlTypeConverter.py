import sys
import re
import clang.cindex
import asciitree  # m

from data import *
from IdlFactory import IdlFactory


class CppToIdlTypeConverter:
    """
   C++	IDL
   bool	boolean
   float	float
   double	double
   char	byte
   char*	DOMString (represents a JavaScript string)
   unsigned char	octet
   unsigned short int	unsigned short
   unsigned short	unsigned short
   unsigned long	unsigned long
   int	long
   void	void
   void*	any or VoidPtr (see void*)
   """
    UNDEFINED = "_undefined_"
    OPERATOR = "_operator_"
    IGNORED = "_ignored_"
    CONSTANT_EXTENDED_ATTR = "[Const]"

    EXCLUDE_STRINGS = [
    ]

    def __init__(self):
        self.fqn = ""
        self.counter = 0
        self.conversion_map = {
            "bool": "boolean",
            "float": "float",
            "short": "short ",
            "double": "double",
            "char": "byte",
            "char*": "DOMString",
            "unsigned char": "octet",
            "unsigned short int": "unsigned short",
            "unsigned long": "unsigned long",
            "unsigned int": "unsigned long",
            "int": "long",
            "void": "void",
            "void*": "VoidPtr"
        }

    def getCounter(self):
        self.counter += 1
        return self.counter

    def convert_function_params(self, method):
        params = []

        if method:
            for item in filter(None, method.params):
                params.append(self.convert_function_param(method, item))

        return params

    def convert_function_param(self, method, param):
        if param:
            if param.name == "":
                param.name = "arg{}".format(self.getCounter())
            if param.name == "object":
                param.name = "obj"
            return '{} {}'.format(self.convert_type(method.name, param.type), param.name)

    def convert_type(self, method, type):
        kind = type.type.kind

        result = None

        is_const_qualified = type.type.is_const_qualified()

        if (kind == clang.cindex.TypeKind.VOID or
                    kind == clang.cindex.TypeKind.BOOL or
                    kind == clang.cindex.TypeKind.SHORT or
                    kind == clang.cindex.TypeKind.FLOAT or
                    kind == clang.cindex.TypeKind.INT or
                    kind == clang.cindex.TypeKind.UINT):
            if is_const_qualified:
                result = self.get_primitive_type(type.type.spelling.split(" ")[1])
            else:
                result = self.get_primitive_type(type.type.spelling)
        if kind == clang.cindex.TypeKind.POINTER:
            result = self.parse_pointer_type(type.type.spelling)
        if kind == clang.cindex.TypeKind.LVALUEREFERENCE:
            result = self.parse_pointer_type(type.type.spelling)
        if kind == clang.cindex.TypeKind.RVALUEREFERENCE:
            # self.dump_cursor(type.node)
            result = self.OPERATOR
        if kind == clang.cindex.TypeKind.UNEXPOSED:
            # self.dump_cursor(type.node)
            result = self.get_primitive_type(type.type.spelling, True)

        if result:
            if is_const_qualified:
                return "{} {}".format(self.CONSTANT_EXTENDED_ATTR, result)
            else:
                return result

        return self.UNDEFINED

    def get_primitive_type(self, str, is_pointer=False):
        if is_pointer:
            return self.IGNORED
            # if self.conversion_map.get(str):
            #    return self.conversion_map.get(str)
            # else:
            #    return self.sanitize_string(str)

        result = self.conversion_map.get(str)

        if result:
            return result

        if not result:
            return self.UNDEFINED

        return "__{} {}".format(result, str)

    def parse_pointer_type(self, type):
        decl = type.split(" ")
        el = decl.pop(0)

        if el == "const":
            primitive = decl.pop(0)
            result = "{} {}".format(self.CONSTANT_EXTENDED_ATTR,
                                    self.get_primitive_type(primitive, True)
                                    )
        else:
            primitive = el
            result = self.get_primitive_type(primitive, True)

        if primitive == "void":
            return self.UNDEFINED

        return result

    def check_hidden_method(self, method):
        result = False

        for item in method:
            restricted = [self.UNDEFINED, self.OPERATOR, self.IGNORED]
            restricted += self.EXCLUDE_STRINGS
            restricted_pattern = '(\\b{0}\\b)'.format('\\b|\\b'.join(restricted))

            if re.search(restricted_pattern, item):
                result = True

        return result

    def convert_class(self, uml_instance):
        return IdlFactory.getConvertedClass(uml_instance)

    def getIdlInstanceName(self, umlInstance):
        idl_label = IdlLabel()
        idl_label.name = umlInstance.fqn

        return idl_label

    def convert_method(self, *function_tuple):
        if function_tuple[0] is None:
            return None

        return_argument = function_tuple[0][0]
        function_name = function_tuple[0][1]
        method = function_tuple[0][2]

        idl_public_method = IdlPublicMethod()
        idl_public_method.name = IdlLabel(function_name)
        idl_public_method.returnType = self.convert_type(function_name, method.returnType)
        idl_public_method.methodParams = self.convert_function_params(method)
        return idl_public_method

    def dump_cursor(self, cursor):
        print asciitree.draw_tree(cursor, self.node_children, self.print_node)

    def node_children(self, node):
        return list(c for c in node.get_children() if c.location.file.name == sys.argv[1])

    def print_node(self, node):
        text = node.spelling or node.displayname
        kind = str(node.kind)[str(node.kind).index('.') + 1:]
        return '{} {} | {}'.format(kind, text, node.type.spelling)
