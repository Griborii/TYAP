from nodes.expressions.Expression import Expression


class EqualExpression(Expression):
    def __init__(self, left: Expression, right: Expression):
        self.left = left
        self.right = right

    def accept(self, visitor):
        return visitor.visit_equal_expression(self)
