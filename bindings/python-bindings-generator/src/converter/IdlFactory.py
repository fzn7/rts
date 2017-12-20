from data import *


def getIdlInstanceName(uml_instance):
    return IdlLabel(uml_instance.fqn)


def getIdlPublicMethod(uml_method_tuple):
    if uml_method_tuple is None:
        return None

    uml_method = uml_method_tuple[2]
    result = IdlPublicMethod(uml_method)

    class_name = uml_method_tuple[0]
    if class_name == result.name.label:
        uml_method.comments += ["Constructor"]

    return result


class IdlFactory:
    @classmethod
    def getConvertedClass(cls, uml_instance):
        idl_instance = IdlInstance()
        idl_instance.name = getIdlInstanceName(uml_instance)
        idl_instance.publicMethods = map(getIdlPublicMethod, uml_instance.publicMethods)

        return idl_instance
