from IdlBaseItem import IdlBaseItem
import re

pattern = re.compile("::")


class IdlLabel(IdlBaseItem):
    def __init__(self, label=None):
        IdlBaseItem.__init__(self)
        self.label = None

        self.parseLabel(label)

    def parseLabel(self, label):
        if pattern.search(label):
            self.label = label.replace("::", "_")
            self.ignoreFlag = True
        else:
            self.label = label