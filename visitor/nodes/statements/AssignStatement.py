from nodes.expressions.Expression import Expression
from nodes.statements.Statement import Statement

class AssignStatement(Statement):
    def __init__(self, variable, expression: Expression):
        self.variable = variable
        self.expression = expression

    def accept(self, visitor):
        return visitor.visit_assign_statement(self)
