from nodes.expressions.Expression import Expression


class NotEqualExpression(Expression):
    def __init__(self, left: Expression, right: Expression):
        self.left = left
        self.right = right

    def accept(self, visitor):
        return visitor.visit_notequal_expression(self)
