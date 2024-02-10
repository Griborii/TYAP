# Generated from Expr.g4 by ANTLR 4.13.1
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO

def serializedATN():
    return [
        4,1,28,116,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        0,1,0,5,0,16,8,0,10,0,12,0,19,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,37,8,1,10,1,12,1,40,9,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,53,8,1,10,1,12,1,56,
        9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,66,8,1,1,1,1,1,3,1,70,8,
        1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,86,
        8,2,1,2,1,2,1,2,1,2,5,2,92,8,2,10,2,12,2,95,9,2,1,2,1,2,1,2,3,2,
        100,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,111,8,2,10,2,12,
        2,114,9,2,1,2,0,1,4,3,0,2,4,0,3,1,0,13,14,1,0,15,16,1,0,17,21,129,
        0,6,1,0,0,0,2,69,1,0,0,0,4,99,1,0,0,0,6,7,5,1,0,0,7,8,5,2,0,0,8,
        9,5,3,0,0,9,10,5,4,0,0,10,11,5,5,0,0,11,17,5,23,0,0,12,13,3,2,1,
        0,13,14,5,23,0,0,14,16,1,0,0,0,15,12,1,0,0,0,16,19,1,0,0,0,17,15,
        1,0,0,0,17,18,1,0,0,0,18,20,1,0,0,0,19,17,1,0,0,0,20,21,5,6,0,0,
        21,1,1,0,0,0,22,23,5,7,0,0,23,24,5,3,0,0,24,25,3,4,2,0,25,26,5,4,
        0,0,26,70,1,0,0,0,27,28,5,8,0,0,28,29,5,3,0,0,29,30,3,4,2,0,30,31,
        5,4,0,0,31,32,5,5,0,0,32,38,5,23,0,0,33,34,3,2,1,0,34,35,5,23,0,
        0,35,37,1,0,0,0,36,33,1,0,0,0,37,40,1,0,0,0,38,36,1,0,0,0,38,39,
        1,0,0,0,39,41,1,0,0,0,40,38,1,0,0,0,41,42,5,6,0,0,42,70,1,0,0,0,
        43,44,5,9,0,0,44,45,5,3,0,0,45,46,3,4,2,0,46,47,5,4,0,0,47,48,5,
        5,0,0,48,54,5,23,0,0,49,50,3,2,1,0,50,51,5,23,0,0,51,53,1,0,0,0,
        52,49,1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,57,1,
        0,0,0,56,54,1,0,0,0,57,58,5,6,0,0,58,70,1,0,0,0,59,66,5,28,0,0,60,
        61,5,28,0,0,61,62,5,10,0,0,62,63,3,4,2,0,63,64,5,11,0,0,64,66,1,
        0,0,0,65,59,1,0,0,0,65,60,1,0,0,0,66,67,1,0,0,0,67,68,5,12,0,0,68,
        70,3,4,2,0,69,22,1,0,0,0,69,27,1,0,0,0,69,43,1,0,0,0,69,65,1,0,0,
        0,70,3,1,0,0,0,71,72,6,2,-1,0,72,73,5,3,0,0,73,74,3,4,2,0,74,75,
        5,4,0,0,75,100,1,0,0,0,76,100,5,26,0,0,77,100,5,25,0,0,78,100,5,
        27,0,0,79,86,5,28,0,0,80,81,5,28,0,0,81,82,5,10,0,0,82,83,3,4,2,
        0,83,84,5,11,0,0,84,86,1,0,0,0,85,79,1,0,0,0,85,80,1,0,0,0,86,100,
        1,0,0,0,87,93,5,10,0,0,88,89,3,4,2,0,89,90,5,22,0,0,90,92,1,0,0,
        0,91,88,1,0,0,0,92,95,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,96,
        1,0,0,0,95,93,1,0,0,0,96,97,3,4,2,0,97,98,5,11,0,0,98,100,1,0,0,
        0,99,71,1,0,0,0,99,76,1,0,0,0,99,77,1,0,0,0,99,78,1,0,0,0,99,85,
        1,0,0,0,99,87,1,0,0,0,100,112,1,0,0,0,101,102,10,9,0,0,102,103,7,
        0,0,0,103,111,3,4,2,10,104,105,10,8,0,0,105,106,7,1,0,0,106,111,
        3,4,2,9,107,108,10,7,0,0,108,109,7,2,0,0,109,111,3,4,2,8,110,101,
        1,0,0,0,110,104,1,0,0,0,110,107,1,0,0,0,111,114,1,0,0,0,112,110,
        1,0,0,0,112,113,1,0,0,0,113,5,1,0,0,0,114,112,1,0,0,0,10,17,38,54,
        65,69,85,93,99,110,112
    ]

class ExprParser ( Parser ):

    grammarFileName = "Expr.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'fun'", "'main'", "'('", "')'", "'{'", 
                     "'}'", "'print'", "'if'", "'while'", "'['", "']'", 
                     "'='", "'*'", "'/'", "'+'", "'-'", "'>'", "'<'", "'=='", 
                     "'<='", "'>='", "','" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "NEWLINE", 
                      "SPACE", "BOOL", "STRING", "INT", "IDENT" ]

    RULE_prog = 0
    RULE_stmt = 1
    RULE_expr = 2

    ruleNames =  [ "prog", "stmt", "expr" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    T__7=8
    T__8=9
    T__9=10
    T__10=11
    T__11=12
    T__12=13
    T__13=14
    T__14=15
    T__15=16
    T__16=17
    T__17=18
    T__18=19
    T__19=20
    T__20=21
    T__21=22
    NEWLINE=23
    SPACE=24
    BOOL=25
    STRING=26
    INT=27
    IDENT=28

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.13.1")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class ProgContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def NEWLINE(self, i:int=None):
            if i is None:
                return self.getTokens(ExprParser.NEWLINE)
            else:
                return self.getToken(ExprParser.NEWLINE, i)

        def stmt(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.StmtContext)
            else:
                return self.getTypedRuleContext(ExprParser.StmtContext,i)


        def getRuleIndex(self):
            return ExprParser.RULE_prog

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProg" ):
                listener.enterProg(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProg" ):
                listener.exitProg(self)

        def accept(self, visitor: ParseTreeVisitor):
            if hasattr(visitor, "visitProg"):
                return visitor.visitProg(self)
            else:
                return visitor.visitChildren(self)


    def prog(self):

        localctx = ExprParser.ProgContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_prog)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 6
            self.match(ExprParser.T__0)
            self.state = 7
            self.match(ExprParser.T__1)
            self.state = 8
            self.match(ExprParser.T__2)
            self.state = 9
            self.match(ExprParser.T__3)
            self.state = 10
            self.match(ExprParser.T__4)
            self.state = 11
            self.match(ExprParser.NEWLINE)
            self.state = 17
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while (((_la) & ~0x3f) == 0 and ((1 << _la) & 268436352) != 0):
                self.state = 12
                self.stmt()
                self.state = 13
                self.match(ExprParser.NEWLINE)
                self.state = 19
                self._errHandler.sync(self)
                _la = self._input.LA(1)

            self.state = 20
            self.match(ExprParser.T__5)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class StmtContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.printexpr = None # ExprContext
            self.ifstatement = None # ExprContext
            self.whilestatement = None # ExprContext
            self.ident = None # Token
            self.index = None # ExprContext
            self.assignexpr = None # ExprContext

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExprParser.ExprContext,i)


        def NEWLINE(self, i:int=None):
            if i is None:
                return self.getTokens(ExprParser.NEWLINE)
            else:
                return self.getToken(ExprParser.NEWLINE, i)

        def stmt(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.StmtContext)
            else:
                return self.getTypedRuleContext(ExprParser.StmtContext,i)


        def IDENT(self):
            return self.getToken(ExprParser.IDENT, 0)

        def getRuleIndex(self):
            return ExprParser.RULE_stmt

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterStmt" ):
                listener.enterStmt(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitStmt" ):
                listener.exitStmt(self)

        def accept(self, visitor: ParseTreeVisitor):
            if hasattr(visitor, "visitStmt"):
                return visitor.visitStmt(self)
            else:
                return visitor.visitChildren(self)


    def stmt(self):

        localctx = ExprParser.StmtContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_stmt)
        self._la = 0 # Token type
        try:
            self.state = 69
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [7]:
                self.enterOuterAlt(localctx, 1)
                self.state = 22
                self.match(ExprParser.T__6)
                self.state = 23
                self.match(ExprParser.T__2)
                self.state = 24
                localctx.printexpr = self.expr(0)
                self.state = 25
                self.match(ExprParser.T__3)
                pass
            elif token in [8]:
                self.enterOuterAlt(localctx, 2)
                self.state = 27
                self.match(ExprParser.T__7)
                self.state = 28
                self.match(ExprParser.T__2)
                self.state = 29
                localctx.ifstatement = self.expr(0)
                self.state = 30
                self.match(ExprParser.T__3)
                self.state = 31
                self.match(ExprParser.T__4)
                self.state = 32
                self.match(ExprParser.NEWLINE)
                self.state = 38
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while (((_la) & ~0x3f) == 0 and ((1 << _la) & 268436352) != 0):
                    self.state = 33
                    self.stmt()
                    self.state = 34
                    self.match(ExprParser.NEWLINE)
                    self.state = 40
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)

                self.state = 41
                self.match(ExprParser.T__5)
                pass
            elif token in [9]:
                self.enterOuterAlt(localctx, 3)
                self.state = 43
                self.match(ExprParser.T__8)
                self.state = 44
                self.match(ExprParser.T__2)
                self.state = 45
                localctx.whilestatement = self.expr(0)
                self.state = 46
                self.match(ExprParser.T__3)
                self.state = 47
                self.match(ExprParser.T__4)
                self.state = 48
                self.match(ExprParser.NEWLINE)
                self.state = 54
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while (((_la) & ~0x3f) == 0 and ((1 << _la) & 268436352) != 0):
                    self.state = 49
                    self.stmt()
                    self.state = 50
                    self.match(ExprParser.NEWLINE)
                    self.state = 56
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)

                self.state = 57
                self.match(ExprParser.T__5)
                pass
            elif token in [28]:
                self.enterOuterAlt(localctx, 4)
                self.state = 65
                self._errHandler.sync(self)
                la_ = self._interp.adaptivePredict(self._input,3,self._ctx)
                if la_ == 1:
                    self.state = 59
                    localctx.ident = self.match(ExprParser.IDENT)
                    pass

                elif la_ == 2:
                    self.state = 60
                    localctx.ident = self.match(ExprParser.IDENT)
                    self.state = 61
                    self.match(ExprParser.T__9)
                    self.state = 62
                    localctx.index = self.expr(0)
                    self.state = 63
                    self.match(ExprParser.T__10)
                    pass


                self.state = 67
                self.match(ExprParser.T__11)
                self.state = 68
                localctx.assignexpr = self.expr(0)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class ExprContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.left = None # ExprContext
            self.exp = None # ExprContext
            self.str_ = None # Token
            self.bool_ = None # Token
            self.val = None # Token
            self.ident = None # Token
            self.index = None # ExprContext
            self.list_ = None # Token
            self.op = None # Token
            self.right = None # ExprContext

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(ExprParser.ExprContext)
            else:
                return self.getTypedRuleContext(ExprParser.ExprContext,i)


        def STRING(self):
            return self.getToken(ExprParser.STRING, 0)

        def BOOL(self):
            return self.getToken(ExprParser.BOOL, 0)

        def INT(self):
            return self.getToken(ExprParser.INT, 0)

        def IDENT(self):
            return self.getToken(ExprParser.IDENT, 0)

        def getRuleIndex(self):
            return ExprParser.RULE_expr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExpr" ):
                listener.enterExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExpr" ):
                listener.exitExpr(self)

        def accept(self, visitor: ParseTreeVisitor):
            if hasattr(visitor, "visitExpr"):
                return visitor.visitExpr(self)
            else:
                return visitor.visitChildren(self)

    def expr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = ExprParser.ExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 4
        self.enterRecursionRule(localctx, 4, self.RULE_expr, _p)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 99
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [3]:
                self.state = 72
                self.match(ExprParser.T__2)
                self.state = 73
                localctx.exp = self.expr(0)
                self.state = 74
                self.match(ExprParser.T__3)
                pass
            elif token in [26]:
                self.state = 76
                localctx.str_ = self.match(ExprParser.STRING)
                pass
            elif token in [25]:
                self.state = 77
                localctx.bool_ = self.match(ExprParser.BOOL)
                pass
            elif token in [27]:
                self.state = 78
                localctx.val = self.match(ExprParser.INT)
                pass
            elif token in [28]:
                self.state = 85
                self._errHandler.sync(self)
                la_ = self._interp.adaptivePredict(self._input,5,self._ctx)
                if la_ == 1:
                    self.state = 79
                    localctx.ident = self.match(ExprParser.IDENT)
                    pass

                elif la_ == 2:
                    self.state = 80
                    localctx.ident = self.match(ExprParser.IDENT)
                    self.state = 81
                    self.match(ExprParser.T__9)
                    self.state = 82
                    localctx.index = self.expr(0)
                    self.state = 83
                    self.match(ExprParser.T__10)
                    pass


                pass
            elif token in [10]:
                self.state = 87
                localctx.list_ = self.match(ExprParser.T__9)
                self.state = 93
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,6,self._ctx)
                while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                    if _alt==1:
                        self.state = 88
                        self.expr(0)
                        self.state = 89
                        self.match(ExprParser.T__21) 
                    self.state = 95
                    self._errHandler.sync(self)
                    _alt = self._interp.adaptivePredict(self._input,6,self._ctx)

                self.state = 96
                self.expr(0)
                self.state = 97
                self.match(ExprParser.T__10)
                pass
            else:
                raise NoViableAltException(self)

            self._ctx.stop = self._input.LT(-1)
            self.state = 112
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,9,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 110
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,8,self._ctx)
                    if la_ == 1:
                        localctx = ExprParser.ExprContext(self, _parentctx, _parentState)
                        localctx.left = _prevctx
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 101
                        if not self.precpred(self._ctx, 9):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 9)")
                        self.state = 102
                        localctx.op = self._input.LT(1)
                        _la = self._input.LA(1)
                        if not(_la==13 or _la==14):
                            localctx.op = self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 103
                        localctx.right = self.expr(10)
                        pass

                    elif la_ == 2:
                        localctx = ExprParser.ExprContext(self, _parentctx, _parentState)
                        localctx.left = _prevctx
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 104
                        if not self.precpred(self._ctx, 8):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 8)")
                        self.state = 105
                        localctx.op = self._input.LT(1)
                        _la = self._input.LA(1)
                        if not(_la==15 or _la==16):
                            localctx.op = self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 106
                        localctx.right = self.expr(9)
                        pass

                    elif la_ == 3:
                        localctx = ExprParser.ExprContext(self, _parentctx, _parentState)
                        localctx.left = _prevctx
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 107
                        if not self.precpred(self._ctx, 7):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 7)")
                        self.state = 108
                        localctx.op = self._input.LT(1)
                        _la = self._input.LA(1)
                        if not((((_la) & ~0x3f) == 0 and ((1 << _la) & 4063232) != 0)):
                            localctx.op = self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 109
                        localctx.right = self.expr(8)
                        pass

             
                self.state = 114
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,9,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[2] = self.expr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def expr_sempred(self, localctx:ExprContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 9)
         

            if predIndex == 1:
                return self.precpred(self._ctx, 8)
         

            if predIndex == 2:
                return self.precpred(self._ctx, 7)
         




