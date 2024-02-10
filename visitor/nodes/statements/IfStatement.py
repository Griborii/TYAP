from nodes.expressions.BoolExpression import BoolExpression
from nodes.statements.Statement import Statement


class IfStatement(Statement):
    def __init__(self, condition: BoolExpression, statements: list[Statement]):
        self.condition = condition
        self.statements = statements

    def accept(self, visitor):
        return visitor.visit_if_statement(self)
