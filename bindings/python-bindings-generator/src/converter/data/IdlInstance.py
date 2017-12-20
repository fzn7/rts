from IdlBaseItem import IdlBaseItem


class IdlInstance(IdlBaseItem):
    def __init__(self):
        IdlBaseItem.__init__(self)

        self.package = None
        self.name = None
        self.parentEntity = None
        self.publicMethods = []

    def ignoreFlagPresent(self):
        result = False

        result |= self.name.ignoreFlag

        if result is True:
            self.comments += ["Ignored by name (typedef needed)"]

        return result
