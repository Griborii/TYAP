from ExprParser import ExprParser
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

class ExprVisitor(ParseTreeVisitor):
    def visitProg(self, ctx : ExprParser.ProgContext):
        statements = []
        for statement in ctx.stmt():
            statements.append(self.visit(statement))
        return Program(statements)

    def visitStmt(self, ctx):
        if ctx.printexpr is not None:
            return PrintStatement(self.visit(ctx.printexpr))
        if ctx.ifstatement is not None:
            statements = []
            for stat in ctx.stmt():
                statements.append(self.visit(stat))
            return IfStatement(self.visit(ctx.ifstatement), statements)
        if ctx.whilestatement is not None:
            statements = []
            for stat in ctx.stmt():
                statements.append(self.visit(stat))
            return WhileStatement(self.visit(ctx.whilestatement), statements)
        if ctx.assignexpr is not None:
            if ctx.index is not None:
                return AssignStatement(AccessByIndexExpression(ctx.ident.text, self.visit(ctx.index)), self.visit(ctx.assignexpr))
            return AssignStatement(ctx.ident.text, self.visit(ctx.assignexpr))

    def visitExpr(self, ctx):
        if ctx.op is not None and ctx.op.text == '+':
            return AddExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '-':
            return SubExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '*':
            return MulExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '/':
            return DivExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '<':
            return LessExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '>':
            return MoreExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '==':
            return MulExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '<=':
            return LessEqExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.op is not None and ctx.op.text == '>=':
            return MoreEqExpression(self.visit(ctx.left), self.visit(ctx.right))
        if ctx.val is not None:
            return NumberExpression(ctx.val.text)
        if ctx.bool_ is not None:
            return BoolExpression(ctx.bool_.text)
        if ctx.exp is not None:
            return BraceExpression(self.visit(ctx.exp))
        if ctx.str_ is not None:
            return StrExpression(ctx.str_.text[1:-1])
        if ctx.ident is not None:
            if ctx.index is not None:
                return AccessByIndexExpression(ctx.ident.text, self.visit(ctx.index))
            return IdentExpression(ctx.ident.text)
        if ctx.list_ is not None:
            elements = []
            for exp in ctx.expr():
                elements.append(self.visit(exp))
            return ListExpression(elements)

        

