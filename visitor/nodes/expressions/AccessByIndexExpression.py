from nodes.expressions.Expression import Expression


class AccessByIndexExpression:
    def __init__(self, name: str, index: int):
        self.name = name
        self.index = index

    def accept(self, visitor):
        return visitor.visit_accessbyindex_expression(self)
