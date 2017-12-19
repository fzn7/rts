class CacheUtil:
    def __init__(self):
        pass

    class_cache = {}
    type_cache = {}

    @classmethod
    def add_class(cls, clazz):
        cls.class_cache[clazz.spelling] = []

    @classmethod
    def add_type(cls, type):
        if type.spelling not in cls.type_cache:
            cls.type_cache[type.spelling] = [id(type)]
        else:
            cls.type_cache[type.spelling].append(id(type))

