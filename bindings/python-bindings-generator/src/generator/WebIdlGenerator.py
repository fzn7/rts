import hashlib

import jsonpickle
from mako.template import Template

from converter import CppToIdlTypeConverter
from converter.util import IdlUtil


class UmlClass:
    def __init__(self):
        self.fqn = None
        self.node = None
        self.parents = []
        self.constructors = []
        self.privateFields = []
        self.privateMethods = []
        self.publicFields = []
        self.publicMethods = []
        self.protectedFields = []
        self.protectedMethods = []

    def addParentByFQN(self, fullyQualifiedClassName):
        self.parents.append(fullyQualifiedClassName)

    def getId(self):
        return "id" + str(hashlib.md5(self.fqn).hexdigest())

    def toJSON(self):
        return jsonpickle.encode(self, unpicklable=False)

class UmlConstructor:
    def __init__(self):
        self.params = []
        self.node = None

class UmlMethod:
    def __init__(self):
        self.name = ""
        self.returnType = None
        self.params = []
        self.node = None


class UmlMethodType:
    def __init__(self):
        self.name = ""
        self.node = None
        self.type = None


class UmlMethodParam:
    def __init__(self):
        self.name = ""
        self.kind = ""
        self.type = ""
        self.node = None


class WebIdlGenerator:
    _showPrivMembers = False
    _showProtMembers = False
    _showPubMembers = False
    _drawAssociations = False
    _drawInheritances = False

    def __init__(self):
        self.classes = {}
        self.converter = CppToIdlTypeConverter()

    def addClass(self, aClass):
        if self.classes.has_key(aClass.fqn):
            if len(aClass.publicMethods) > len(self.classes[aClass.fqn].publicMethods):
                self.classes[aClass.fqn] = aClass
        else:
            self.classes[aClass.fqn] = aClass


    def _genFields(self, accessPrefix, fields):
        ret = "".join([(accessPrefix + fieldName + ": " + fieldType + "\l") for fieldName, fieldType in fields])
        return ret

    def _genMethods(self, accessPrefix, methods):
        return "".join([(accessPrefix + methodName + methodArgs + " : " + returnType + "\l") for
                        (returnType, methodName, methodArgs) in methods])

    def _genClass(self, aClass, withPublicMembers=False, withProtectedMembers=False, withPrivateMembers=False):
        c = (aClass.getId() + " [ \n" +
             "   label = \"{" + aClass.fqn)

        if withPublicMembers:
            pubFields = self._genFields('+ ', aClass.publicFields)
            pubMethods = self._genMethods('+ ', aClass.publicMethods)

            if len(pubFields) != 0 or len(pubMethods) != 0:
                c += "|" + pubFields + pubMethods

        if withProtectedMembers:
            protFields = self._genFields('# ', aClass.protectedFields)
            protMethods = self._genMethods('# ', aClass.protectedMethods)

            if len(protFields) != 0 or len(protMethods) != 0:
                c += "|" + protFields + protMethods

        if withPrivateMembers:
            privateFields = self._genFields('- ', aClass.privateFields)
            privateMethods = self._genMethods('- ', aClass.privateMethods)

            if len(privateFields) != 0 or len(privateMethods) != 0:
                c += "|" + privateFields + privateMethods

        c += "}\"  ]\n"
        c = c.replace('<', '\\<')
        c = c.replace('>', '\\>')
        return c

    def _genAssociations(self, aClass):
        edges = set()
        for fieldName, fieldType in aClass.privateFields:
            if fieldType in self.classes:
                c = self.classes[fieldType]
                edges.add(aClass.getId() + "->" + c.getId())
        for fieldName, fieldType in aClass.publicFields:
            if fieldType in self.classes:
                c = self.classes[fieldType]
                edges.add(aClass.getId() + "->" + c.getId())
        edgesJoined = "\n".join(edges)
        return edgesJoined + "\n" if edgesJoined != "" else ""

    def _genInheritances(self, aClass):
        edges = ""
        for parent in aClass.parents:
            if parent in self.classes:
                c = self.classes[parent]
                edges += (aClass.getId() + "->" + c.getId() + "\n")
        return edges

    def setDrawInheritances(self, enable):
        self._drawInheritances = enable

    def setDrawAssociations(self, enable):
        self._drawAssociations = enable

    def setShowPrivMethods(self, enable):
        self._showPrivMembers = enable

    def setShowProtMethods(self, enable):
        self._showProtMembers = enable

    def setShowPubMethods(self, enable):
        self._showPubMembers = enable

    def generate(self):
        # associations
        """
        if self._drawAssociations:
            associations = ""
            for key, aClass in self.classes.iteritems():
                associations += self._genAssociations(aClass)

            if associations != "":
                dotContent += ("\nedge [arrowhead = open]\n")
                dotContent += associations

        # inheritances
        if self._drawInheritances:
            inheritances = ""
            for key, aClass in self.classes.iteritems():
                inheritances += self._genInheritances(aClass)

            if inheritances != "":
                dotContent += ("\nedge [arrowhead = empty]\n")
                dotContent += inheritances

        dotContent += "}\n"
        """
        tpl = Template(filename='bind_idl.mako')

        # for k in self.classes:
        #    print self.classes.get(k).fqn

        print "--- public interfaces discovered ---"
        print ", ".join(map(lambda i: i[1].fqn, self.classes.items()))

        interfaces = list(filter(lambda item: len(item[1].publicMethods) > 0, self.classes.items()))

        print "--- public interfaces to convert ---"
        print ", ".join(map(lambda i: i[1].fqn, interfaces))

        idl_classes = {k: self.converter.convert_class(v) for k, v in interfaces}
        config = IdlUtil.IDLUtil.get_api_config()
        # filter by key
        idl_classes = {k: v for k, v in filter(lambda item: item[1].name.label in config, idl_classes.iteritems())}

        rendered = tpl.render(
            classes=idl_classes,
            module_name='CodegenExample')

        return rendered, idl_classes

    def tmp(self, item):
        print item
