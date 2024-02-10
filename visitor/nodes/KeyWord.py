from antlr.nodes.expressions.Expression import Expression


class KeyWord(Expression):
    def __init__(self, word):
        super().__init__("KEYWORD")
        self.value = word

    def __str__(self):
        return f"{self.name}({self.value})"