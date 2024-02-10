import ExprParser
import abc
from antlr4 import *

from nodes.expressions.AccessByIndexExpression import AccessByIndexExpression
from nodes.expressions.AddExpression import AddExpression
from nodes.expressions.BoolExpression import BoolExpression
from nodes.expressions.BraceExpression import BraceExpression
from nodes.expressions.DivExpression import DivExpression
from nodes.expressions.EqualExpression import EqualExpression
from nodes.expressions.IdentExpression import IdentExpression
from nodes.expressions.LessExpression import LessExpression
from nodes.expressions.LessEqExpression import LessEqExpression
from nodes.expressions.ListStatement import ListExpression
from nodes.expressions.MoreExpression import MoreExpression
from nodes.expressions.MoreEqExpression import MoreEqExpression
from nodes.expressions.MulExpression import MulExpression
from nodes.expressions.NotEqual import NotEqualExpression
from nodes.expressions.NumberExpression import NumberExpression
from nodes.expressions.SubExpression import SubExpression
from nodes.expressions.StrExpression import StrExpression

from nodes.statements.AssignStatement import AssignStatement
from nodes.statements.IfStatement import IfStatement
from nodes.statements.PrintStatement import PrintStatement
from nodes.statements.WhileStatement import WhileStatement

from nodes.Program import Program
from visitors.Visitor import Visitor

class InterpreterVisitor(Visitor):
    def __init__(self) -> None:
        self.variables = {}

    def visit_number_expression(self, expression: NumberExpression):
        return expression.number

    def visit_string_expression(self, expression: StrExpression):
        return expression.str

    def visit_bool_expression(self, expression: BoolExpression):
        return expression.bool

    def visit_add_expression(self, expression: AddExpression):
        return expression.left.accept(self) + expression.right.accept(self)

    def visit_sub_expression(self, expression: SubExpression):
        return expression.left.accept(self) - expression.right.accept(self)

    def visit_mul_expression(self, expression: MulExpression):
        return expression.left.accept(self) * expression.right.accept(self)

    def visit_div_expression(self, expression: DivExpression):
        return expression.left.accept(self) // expression.right.accept(self)

    def visit_brace_expression(self, expression: BraceExpression):
        return expression.expression.accept(self)

    def visit_less_expression(self, expression: LessExpression):
        return expression.left.accept(self) < expression.right.accept(self)
    
    def visit_less_eq_expression(self, expression: LessEqExpression):
        return expression.left.accept(self) <= expression.right.accept(self)
    
    def visit_more_expression(self, expression: MoreExpression):
        return expression.left.accept(self) < expression.right.accept(self)
    
    def visit_more_eq_expression(self, expression: MoreEqExpression):
        return expression.left.accept(self) <= expression.right.accept(self)
    
    def visit_equal_expression(self, expression: EqualExpression):
        return expression.left.accept(self) == expression.right.accept(self)

    def visit_notequal_expression(self, expression: NotEqualExpression):
        return expression.left.accept(self) != expression.right.accept(self)

    def visit_program(self, program: Program):
        for expression in program.expressions:
            expression.accept(self)

    def visit_if_statement(self, statement: IfStatement):
        if statement.condition.accept(self):
            for stat in statement.statements:
                stat.accept(self)

    def visit_while_statement(self, statement: WhileStatement):
        while statement.condition.accept(self):
            for stat in statement.statements:
                stat.accept(self)

    def visit_assign_statement(self, statement: AssignStatement):
        var = statement.variable
        if hasattr(var, "name"):
            self.variables[var.name][var.index.accept(self)] = statement.expression.accept(self)
        self.variables[var] = statement.expression.accept(self)

    def visit_list_expression(self, statement: ListExpression):
        list_ = []
        for elem in statement.elements:
            list_.append(elem.accept(self))
        return list_

    def visit_print_statement(self, statement: PrintStatement):
        print(statement.expression.accept(self))

    def visit_accessbyindex_expression(self, expression: AccessByIndexExpression):
        if expression.name[0] not in self.variables:
            raise ValueError(f'Variable {expression.name[0]} not found')
        return self.variables[expression.name][expression.index.accept(self)]

    def visit_ident_expression(self, expression: IdentExpression):
        if expression.name not in self.variables:
            raise ValueError(f'Variable {expression.name} not found')
        return self.variables[expression.name]