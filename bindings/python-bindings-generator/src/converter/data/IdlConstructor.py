from IdlBaseItem import IdlBaseItem
from IdlFunctionArgument import IdlFunctionArgument
from IdlLabel import IdlLabel


class IdlConstructor(IdlBaseItem):
    def __init__(self, uml_method):
        IdlBaseItem.__init__(self)
        self.name = None
        self.arguments = []
        self.uml_method = uml_method

        self.parsePublicMethod(uml_method)

    def ignore(self):
        result = self.name.ignoreFlag | self.returnType.ignoreFlag

        for methodParam in self.methodParams:
            result |= methodParam.ignoreFlag

        return result


    def parsePublicMethod(self, uml_method):
        self.name = self.parseMethodName(uml_method)
        self.arguments = list(map(self.parseFunctionArgument, list(uml_method.node.get_arguments())))

        self.comments += self.name.comments

        if len(self.arguments) > 0:
            self.comments += ["Argument list sized: {}".format(len(self.arguments))]
            self.comments += list(map(lambda argument: argument.comments, self.arguments))

        self.ignoreFlag = self.validate()

    def parseMethodName(self, uml_method):
        idl_label = IdlLabel(uml_method.name)
        return idl_label

    def parseFunctionArgument(self, uml_method_param):
        result = IdlFunctionArgument(uml_method_param)

        return result

    def ignoreFlagPresent(self):
        return self.ignoreFlag

    def validate(self):
        result = False

        result |= self.name.ignoreFlag

        if result is True:
            self.comments += ["Ignored by method name"]

        result |= len(self.arguments) > 0
        if result is True:
            self.comments += ["Ignored by has arguments"]

        return result
