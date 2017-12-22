from IdlBaseItem import IdlBaseItem
from clang.cindex import CursorKind


class IdlInstance(IdlBaseItem):
    def __init__(self, uml_instance):
        IdlBaseItem.__init__(self)

        self.package = None
        self.rawInstance = uml_instance
        self.name = None
        self.sourceFile = None
        self.parentEntity = None
        self.publicMethods = []

        self.ignoreFlag = self.validate(uml_instance)

    def ignoreFlagPresent(self):
        result = False

        result |= self.ignoreFlag
        if result is True:
            return result

        result |= self.name.ignoreFlag
        if result is True:
            self.comments += ["Ignored by name (typedef needed)"]

        return result

    def validate(self, uml_instance):
        result = False

        if uml_instance.node.kind == CursorKind.CLASS_TEMPLATE:
            self.comments += ["Ignored by class template kind"]
            result = True

        return result
