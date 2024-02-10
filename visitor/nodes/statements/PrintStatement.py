from nodes.expressions.Expression import Expression
from nodes.statements.Statement import Statement

class PrintStatement(Statement):
    def __init__(self, expression: Expression):
        self.expression = expression

    def accept(self, visitor):
        return visitor.visit_print_statement(self)
