from IdlBaseItem import IdlBaseItem
from IdlLabel import IdlLabel
from IdlType import IdlType


class IdlFunctionArgument(IdlBaseItem):
    def __init__(self, uml_function_argument):
        IdlBaseItem.__init__(self)

        self.label = None
        self.type = None
        self.raw_argument = uml_function_argument

        self.parseFunctionArgument(uml_function_argument)

        self.comments += self.type.comments

    def parseFunctionArgument(self, uml_function_argument):
        self.label = IdlLabel(uml_function_argument.name)
        self.type = IdlType(uml_function_argument.type.type)


