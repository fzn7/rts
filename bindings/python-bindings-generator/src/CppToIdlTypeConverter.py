from WebIdlGenerator import *
import sys
import re


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
        self.conversion_map = {
            "bool": "boolean",
            "float": "float",
            "double": "double",
            "char": "byte",
            "char*": "DOMString",
            "unsigned char": "octet",
            "unsigned short int": "unsigned short",
            "unsigned long": "unsigned long",
            "int": "long",
            "void": "void",
            "void*": "VoidPtr"
        }

    def convert_function_params(self, method):
        if method:
            params = []

            for item in filter(None, method.params):
                params.append(self.convert_function_param(method, item))

            return ', '.join(map(str, params))

        return "undefined"

    def convert_function_param(self, method, param):
        if param:
            return '{} {}'.format(self.convert_type(method.name, param.type), param.name)

    def convert_type(self, method, type):
        tokens = type.split(" ")
        result = []

        while len(tokens) > 0:
            token = tokens.pop(0)
            print token

        result = self.conversion_map.get(type)

        if result:
            return result

        # guess it is classname
        if type.endswith("&") or type.endswith("*"):
            class_type = type[:-2].strip().split(" ")

            if len(class_type) == 1:
                return class_type[0]

            if len(class_type) == 2:
                return class_type.join(" ")

        print "[WARN] can not convert \"{}\" type from \"{}\" method".format(type, method)
        return "undefined"

    def check_hidden_method(self, method):
        result = False

        for item in method:
            if re.match("(\\bany\\b|\\bundefined\\b)", item):
                result = True

        return result

    def convert_method(self, *function_tuple):
        return_argument = function_tuple[0][0]
        function_name = function_tuple[0][1]

        function_params = self.convert_function_params(function_tuple[0][2])
        converted_argument = self.convert_type(function_name, return_argument)

        result = converted_argument, function_name, "{}".format(function_params)

        return result + (self.check_hidden_method(result),)

    def convert_class(self, uml_instance, idl_instance):
        print "--- process class: {}".format(uml_instance.fqn)
        idl_instance.fqn = uml_instance.fqn
        idl_instance.publicMethods = map(self.convert_method, filter(None, uml_instance.publicMethods))

        return idl_instance
