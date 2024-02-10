from nodes.expressions.Expression import Expression


class StrExpression(Expression):
    def __init__(self, line: str):
        self.str = line

    def __bool__(self):
        return self.str != ""

    def accept(self, visitor):
        return visitor.visit_string_expression(self)
