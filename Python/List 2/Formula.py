from itertools import product

# Uwagi/TODO:
# poprawić permsVarVal - niepotrzebne
# Wydzielić klasę binop, nad and or pod Formula


class Formula:

    def oblicz(self, zmienne):
        pass

    def getVars(self):
        pass

    def taut(self):
        _vars = self.getVars()
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
            if (not self.oblicz(evaluation)):
                return False
        return True


class Zmienna(Formula):

    def __init__(self, zmienna):
        self.symbol = zmienna

    def oblicz(self, zmienne):
        return zmienne[self.symbol]

    def __str__(self):
        return self.symbol.__str__()

    def getVars(self):
        return [self.symbol]


class Neg(Formula):

    def __init__(self, form):
        self.form = form

    def oblicz(self, zmienne):
        return not self.form.oblicz(zmienne)

    def __str__(self):
        return "~("+self.form.__str__()+")"

    def getVars(self):
        return list(set(self.form.getVars()))


class And(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " ^ "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) and self.right.oblicz(zmienne)

    def __str__(self):
        ret = "("+self.left.__str__()+self.symbol.__str__()
        return ret+self.right.__str__()+")"

    def getVars(self):
        s = set(self.left.getVars())
        for e in set(self.right.getVars()):
            s.add(e)
        return list(s)


class Or(Formula):
    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " v "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) or self.right.oblicz(zmienne)

    def __str__(self):
        ret = "("+self.left.__str__()+self.symbol.__str__()
        return ret+self.right.__str__()+")"

    def getVars(self):
        s = set(self.left.getVars())
        for e in set(self.right.getVars()):
            s.add(e)
        return list(s)


class Impl(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " => "

    def oblicz(self, zmienne):
        return not self.left.oblicz(zmienne) or self.right.oblicz(zmienne)

    def __str__(self):
        ret = "("+self.left.__str__()+self.symbol.__str__()
        return ret+self.right.__str__()+")"

    def getVars(self):
        s = set(self.left.getVars())
        for e in set(self.right.getVars()):
            s.add(e)
        return list(s)


class Iff(Formula):

    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.symbol = " <=> "

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) == self.right.oblicz(zmienne)

    def __str__(self):
        ret = "("+self.left.__str__()+self.symbol.__str__()
        return ret+self.right.__str__()+")"

    def getVars(self):
        s = set(self.left.getVars())
        for e in set(self.right.getVars()):
            s.add(e)
        return list(s)


class true(Formula):

    def __init__(self):
        self.symbol = "True"

    def oblicz(self, zmienne=0):
        return True

    def __str__(self):
        return "T"

    def getVars(self):
        return []


class false(Formula):

    def __init__(self):
        self.symbol = "False"

    def oblicz(self, zmienne=0):
        return False

    def __str__(self):
        return "F"

    def getVars(self):
        return []


print(Or(Zmienna("x"), Zmienna("y")))
print(And(Or(Zmienna("x"), Zmienna("y")),
      Impl(Zmienna("x"), Zmienna("z"))))
print(And(Or(Zmienna("x"), Zmienna("y")),
      Impl(Zmienna("x"), Zmienna("z"))).taut())
print("\n")
print(true())
print(true().taut())
print("\n")
print(Or(Zmienna("x"), Neg(Zmienna("x"))))
print(Or(Zmienna("x"), Neg(Zmienna("x"))).taut())
print("\n")
print(Or(Zmienna("x"), Zmienna("y")))
print(Or(Zmienna("x"), Zmienna("y")).taut())
print("\n")
print(Or(Zmienna("x"), Zmienna("x")))
print(Or(Zmienna("x"), Zmienna("x")).taut())
print("\n")
print(Or(Zmienna("x"), Zmienna("y")))
print(Or(Zmienna("x"), Zmienna("y")).oblicz({"x": True, "y": False}))
print("\n")
print(Impl(Zmienna("x"), Zmienna("y")))
print(Impl(Zmienna("x"), Zmienna("y")).oblicz({"x": True, "y": False}))
print(Impl(Zmienna("x"), Zmienna("y")).oblicz({"x": True, "y": True}))
print(Impl(Zmienna("x"), Zmienna("y")).getVars())
print(And(Or(Zmienna("x"), Zmienna("y")),
      Impl(Zmienna("x"), Zmienna("z"))).getVars())
