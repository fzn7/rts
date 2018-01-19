from sets import Set
import os
import re

class CacheUtil:
    def __init__(self):
        pass

    class_cache = {}
    type_cache = {}
    source_files = Set()

    @classmethod
    def get_wrapper_includes_list(cls, root_path, classes):
        result = list(cls.source_files)
        result = filter(lambda path: path.startswith(root_path), result)
        classes_paths = list(map(lambda (k, v): os.path.abspath(str(v.sourceFile)), classes.iteritems()))
        result = filter(lambda path: path in classes_paths, result)
        result = map(lambda path: path.replace("{}/".format(root_path), ''), result)
        return result

    @classmethod
    def add_class(cls, clazz):
        cls.class_cache[clazz.spelling] = []

    @classmethod
    def add_type(cls, type):
        if type.spelling not in cls.type_cache:
            cls.type_cache[type.spelling] = [id(type)]
        else:
            cls.type_cache[type.spelling].append(id(type))

    @classmethod
    def add_source(cls, sourceFile):
        cls.source_files.add(os.path.abspath(str(sourceFile.name)))


