from nodes.expressions.Expression import Expression


class BoolExpression(Expression):
    def __init__(self, b: str):
        self.bool = True if b == "true" else False
        # print("bool", self.bool)

    def __bool__(self):
        return self.bool 

    def accept(self, visitor):
        return visitor.visit_bool_expression(self)
