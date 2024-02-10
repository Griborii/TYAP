from nodes.expressions.Expression import Expression


class ListExpression:
    def __init__(self, elements: list[Expression]):
        self.elements = elements

    def accept(self, visitor):
        return visitor.visit_list_expression(self)
