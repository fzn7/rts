from IdlBaseItem import IdlBaseItem


class IdlLabel(IdlBaseItem):
    def __init__(self, label=None):
        IdlBaseItem.__init__(self)
        self.label = label
