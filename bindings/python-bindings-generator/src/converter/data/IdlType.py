from IdlBaseItem import IdlBaseItem
from clang.cindex import TypeKind
from converter.util import CacheUtil
from IdlLabel import IdlLabel

conversion_map = {
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


class IdlType(IdlBaseItem):
    def __init__(self, type=None):
        IdlBaseItem.__init__(self)

        self.raw_type = type
        self.is_const = False
        self.kind = None

        self.parseType(type)

    def parseType(self, type):
        CacheUtil.add_type(type)

        type_arr = type.spelling.split(" ")

        self.parseConst(type_arr)

        raw_kind = {
            TypeKind.VOID: lambda node: self.parsePrimitive(node),
            TypeKind.BOOL: lambda node: self.parsePrimitive(node),
            TypeKind.SHORT: lambda node: self.parsePrimitive(node),
            TypeKind.FLOAT: lambda node: self.parsePrimitive(node),
            TypeKind.INT: lambda node: self.parsePrimitive(node),
            TypeKind.UINT: lambda node: self.parsePrimitive(node),
            TypeKind.LVALUEREFERENCE: lambda node: self.parseComplex(node),
            TypeKind.RVALUEREFERENCE: lambda node: self.parseComplex(node),
            TypeKind.POINTER: lambda node: self.parseComplex(node),
            TypeKind.RECORD: lambda node: self.parseComplex(node),
            TypeKind.TYPEDEF: lambda node: self.parseComplex(node),
            TypeKind.ENUM: lambda node: self.parseComplex(node),
            TypeKind.UNEXPOSED: lambda node: self.parseComplex(node),
        }[type.kind](type)

        if raw_kind is not None:
            self.kind = IdlLabel(raw_kind)

            self.comments.append("Type: name: '{}' kind: {} is_const: {} kind: {}"
                                 .format(" ".join(type_arr), type.kind, self.is_const, self.kind.label))

            if type.get_declaration().location:
                self.comments.append("Source: {}".format(type.get_declaration().location))

        self.ignoreFlag = self.validate()

    def parseConst(self, type_arr):
        if type_arr[0] == "const":
            self.is_const = True
            type_arr.pop(0)

    def parsePrimitive(self, type_node):
        #TODO refactor duplicate
        type_arr = type_node.spelling.split(" ")
        if type_arr[0] == "const":
            type_arr.pop(0)
        spelling = " ".join(type_arr)
        return conversion_map.get(spelling)

    def parseComplex(self, type_node):
        return "complex_type"

    def validate(self):
        result = False

        if self.kind is None:
            self.comments += ["Type kind undefined"]
            return True

        if self.kind.label == "complex_type":
            self.comments += ["Ignored by complex type"]
            return True

        return result
