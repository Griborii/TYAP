from nodes.expressions.Expression import Expression


class Program:
    def __init__(
            self,
            expressions: list[Expression]
    ) -> None:
        self.expressions = expressions

    def accept(self, visitor):
        return visitor.visit_program(self)
