from IdlBaseItem import IdlBaseItem


class IdlInstance(IdlBaseItem):
    def __init__(self):
        IdlBaseItem.__init__(self)

        self.package = None
        self.name = None
        self.parentEntity = None
        self.publicMethods = []
