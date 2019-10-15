from itertools import product


class Formula:

    def oblicz(self, zmienne):
        pass


class Zmienna(Formula):

    def __init__(self, zmienna):
        self.symbol = zmienna

    def oblicz(self, zmienne):
        return zmienne[self.symbol]

    def __str__(self):
        return self.symbol.__str__()


class Neg(Formula):

    def __init__(self, form):
        self.symbol = form
        self.left = "~"

    def oblicz(self, zmienne):
        return not self.symbol.oblicz(zmienne)

    def __str__(self):
        return self.left.__str__()+"("+self.symbol.__str__()+")"


class And(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " ^ "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) and self.right.oblicz(zmienne)

    def __str__(self):
        return self.left.__str__()+self.symbol.__str__()+self.right.__str__()


class Or(Formula):
    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " v "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) or self.right.oblicz(zmienne)

    def __str__(self):
        return self.left.__str__()+self.symbol.__str__()+self.right.__str__()


class Impl(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " => "

    def oblicz(self, zmienne):
        return not self.left.oblicz(zmienne) or self.right.oblicz(zmienne)

    def __str__(self):
        return self.left.__str__()+self.symbol.__str__()+self.right.__str__()


class Iff(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " <=> "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) == self.right.oblicz(zmienne)

    def __str__(self):
        return self.left.__str__()+self.symbol.__str__()+self.right.__str__()


class true(Formula):

    def __init__(self):
        self.symbol = "True"

    def oblicz(self, zmienne=0):
        return True


class false(Formula):

    def __init__(self):
        self.symbol = "False"

    def oblicz(self, zmienne=0):
        return False


def taut(form, _vars):
    # https://docs.python.org/3/library/itertools.html#itertools.product
    permsTF = product([True, False], repeat=len(_vars))
    permsVarVal = []
    d = {}
    for val in permsTF:
        for var in range(len(_vars)):
            d[_vars[var]] = val[var]
        permsVarVal.append(d)
        d = {}
    for evaluation in permsVarVal:
        if (not form.oblicz(evaluation)):
            return False
    return True


print(Or(Zmienna("x"), Zmienna("y")))
print(And(Or(Zmienna("x"), Zmienna("y")),
      Impl(Zmienna("x"), Zmienna("z"))))
print(1 > 0)
print(taut(true(), ["y", "x"]))
print(Or(Zmienna("x"), Neg(Zmienna("x"))))
print(taut(Or(Zmienna("x"), Neg(Zmienna("x"))), ["x"]))
print(taut(Or(Zmienna("x"), Zmienna("x")), ["x"]))
