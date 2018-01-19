from IdlBaseItem import IdlBaseItem
import re

namespace_pattern = re.compile("::")
reserved_pattern = re.compile("__")

class IdlLabel(IdlBaseItem):
    def __init__(self, label=None):
        IdlBaseItem.__init__(self)
        self.label = None

        self.parseLabel(label)

    def parseLabel(self, label):
        if namespace_pattern.search(label):
            #self.label = label.replace("::", "_")
            self.ignoreFlag = True
        if reserved_pattern.match(label):
            self.ignoreFlag = True
        else:
            self.label = label