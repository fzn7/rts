from WebIdlGenerator import *
import sys
import re
import clang.cindex
import asciitree  # m

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
        if method:
            params = []

            for item in filter(None, method.params):
                params.append(self.convert_function_param(method, item))

            return ', '.join(map(str, params))

        return "undefined"

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
            self.dump_cursor(type.node)
            result = "__operator__"
        if kind == clang.cindex.TypeKind.UNEXPOSED:
            self.dump_cursor(type.node)
            result = self.get_primitive_type(type.type.spelling, True)

        if result:
            if is_const_qualified:
                return "[Const] {}".format(result)
            else:
                return result

        return "__undefined__"

    def get_primitive_type(self, str, return_not_modify=False):
        print "get_primitive_type {}".format(str)

        if return_not_modify:
            return self.sanitize_string(str)

        result = self.conversion_map.get(str)

        if result:
            return result

        if not result:
            return "__undefined__"

        return "__{} {}".format(result, str)

    def parse_pointer_type(self, type):
        decl = type.split(" ")
        el = decl.pop(0)

        if el == "const":
            primitive = decl.pop(0)
            result = "[Const] {}".format(
                self.get_primitive_type(primitive, True)
            )
        else:
            primitive = el
            result = self.get_primitive_type(primitive, True)

        if primitive == "void":
            return "__undefined__"

        return result

    def check_hidden_method(self, method):
        result = False

        for item in method:
            if re.match("(\\b__undefined__\\b|\\b__operator__\\b|\\boperator\\b)", item):
                result = True

        return result

    def convert_method(self, *function_tuple):
        return_argument = function_tuple[0][0]
        function_name = function_tuple[0][1]
        method = function_tuple[0][2]

        function_params = self.convert_function_params(method)
        converted_argument = self.convert_type(function_name, method.returnType)

        result = converted_argument, function_name, "{}".format(function_params)

        return result + (self.check_hidden_method(result),)

    def sanitize_string(self, str):
        return "__".join(str.split("::"))

    def convert_class(self, uml_instance, idl_instance):
        print "--- process class: {}".format(uml_instance.fqn)
        idl_instance.fqn = self.sanitize_string(uml_instance.fqn)
        idl_instance.publicMethods = map(self.convert_method, filter(None, uml_instance.publicMethods))

        return idl_instance

    def dump_cursor(self, cursor):
        print asciitree.draw_tree(cursor, self.node_children, self.print_node)

    def node_children(self, node):
        return list(c for c in node.get_children() if c.location.file.name == sys.argv[1])

    def print_node(self, node):
        text = node.spelling or node.displayname
        kind = str(node.kind)[str(node.kind).index('.') + 1:]
        return '{} {} | {}'.format(kind, text, node.type.spelling)
