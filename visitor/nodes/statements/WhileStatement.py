from nodes.statements.Statement import Statement
from nodes.expressions.BoolExpression import BoolExpression


class WhileStatement(Statement):
    def __init__(self, condition: BoolExpression, statements: list[Statement]):
        self.condition = condition
        self.statements = statements

    def accept(self, visitor):
        return visitor.visit_while_statement(self)
