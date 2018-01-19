from data import *
from converter.util import CacheUtil
import os

def getIdlInstanceName(uml_instance):
    return IdlLabel(uml_instance.fqn)


def getIdlPublicMethod(uml_method_tuple):
    if uml_method_tuple is None:
        return None

    uml_method = uml_method_tuple[2]
    result = IdlPublicMethod(uml_method)

    return result


def getIdlConstructor(uml_constructor):
    result = IdlConstructor(uml_constructor)
    return result


class IdlFactory:
    @classmethod
    def getConvertedClass(cls, uml_instance):
        idl_instance = IdlInstance(uml_instance)
        idl_instance.name = getIdlInstanceName(uml_instance)
        idl_instance.constructors = map(getIdlConstructor, uml_instance.constructors)

        for constructor in idl_instance.constructors:
            if len(constructor.arguments) == 0:
                idl_instance.defaultConstructor = constructor
                break

        idl_instance.publicMethods = map(getIdlPublicMethod, uml_instance.publicMethods)

        idl_instance.sourceFile = uml_instance.node.location.file
        CacheUtil.add_source(idl_instance.sourceFile)
        idl_instance.comments += ["Source: {}".format(os.path.abspath(str(uml_instance.node.location.file)))]

        return idl_instance
