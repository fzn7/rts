from IdlBaseItem import IdlBaseItem
from clang.cindex import TypeKind
from converter.util import CacheUtil


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

        self.kind = {
            TypeKind.VOID: "void",
            TypeKind.BOOL: "boolean",
            TypeKind.SHORT: "short",
            TypeKind.FLOAT: "float",
            TypeKind.INT: "int",
            TypeKind.UINT: "uint",
            TypeKind.LVALUEREFERENCE: "LVALUEREFERENCE",
            TypeKind.RVALUEREFERENCE: "RVALUEREFERENCE",
            TypeKind.POINTER: "POINTER",
            TypeKind.RECORD: "RECORD",
            TypeKind.TYPEDEF: "TYPEDEF",
            TypeKind.ENUM: "ENUM",
        }[type.kind]

        self.comments.append("Type: name: '{}' kind: {} is_const: {} kind: {}"
                             .format(" ".join(type_arr), type.kind, self.is_const, self.kind))

        if type.get_declaration().location:
            self.comments.append("Source: {}".format(type.get_declaration().location))

    def parseConst(self, type_arr):
        if type_arr[0] == "const":
            self.is_const = True
            type_arr.pop(0)
