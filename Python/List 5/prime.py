from timeit import timeit
from math import sqrt, floor
from functools import partial


def isPrime(n):
    if n in [2, 3]:
        return True
    for x in range(2, int(floor(sqrt(n)))+1):
        if n % x == 0:
            return False
    return True


class Prime_iter:

    def __init__(self, n):
        self.current = 2
        self.max = n

    def __iter__(self):
        self.current = 2

    def __next__(self):
        ret = self.current
        if ret > self.max:
            raise StopIteration
        temp = self.current+1
        while not isPrime(temp):
            temp += 1
        self.current = temp
        return ret


def prime_iter(n):
    ret = []
    it = Prime_iter(n)
    try:
        while True:
            ret.append(it.__next__())
    except StopIteration:
        pass
    return ret


def prime_imp(n):
    out = []
    for x in range(2, n+1):
        if isPrime(x):
            out.append(x)
    return out


def prime_comprehension(n):
    return [x for x in range(2, n+1)
            if all(x % y != 0 for y in range(2, int(floor(sqrt(x)))+1))]


def prime_funct(n):
    return list(filter(lambda x: all(x % y != 0 for y in
                                     range(2, int(floor(sqrt(x)))+1))
                       or x in [2, 3],
                       range(2, n+1)))


set1 = '''
from math import sqrt, floor


def isPrime(n):
    if n in [2, 3]:
        return True
    for x in range(2, int(floor(sqrt(n)))+1):
        if n % x == 0:
            return False
    return True

def prime_imp(n):
    out = []
    for x in range(2, n+1):
        if isPrime(x):
            out.append(x)
    return out
'''
set2 = '''
def prime_comprehension(n):
    return [x for x in range(2, n+1) if all(x % y != 0 for y in range(2, x))]
'''
set3 = '''
from math import sqrt, floor


def prime_funct(n):
    return list(filter(lambda x: all(x % y != 0 for y in
                                     range(2, int(floor(sqrt(x)))+1))
                       or x in [2, 3],
                       range(2, n+1)))
'''
set4 = '''
from math import sqrt, floor


def isPrime(n):
    if n in [2, 3]:
        return True
    for x in range(2, int(floor(sqrt(n)))+1):
        if n % x == 0:
            return False
    return True


class Prime_iter:

    def __init__(self, n):
        self.current = 2
        self.max = n

    def __iter__(self):
        self.current = 2

    def __next__(self):
        ret = self.current
        if ret > self.max:
            raise StopIteration
        temp = self.current+1
        while not isPrime(temp):
            temp += 1
        self.current = temp
        return ret


def prime_iter(n):
    ret = []
    it = Prime_iter(n)
    try:
        while True:
            ret.append(it.__next__())
    except StopIteration:
        pass
    return ret
'''


def _print(p):
    arg = [10, 100, 1000, 10000]
    setups = [set1, set2, set3, set4]
    print("\t| imperatywna\t| funkcyjna\t| skladana\t| iterator")
    for i in range(0, 16, 4):
        t1 = timeit(partial(prime_imp, arg[i/4]), setups[i % 4], number=1)
        temp = setups[(i+1) % 4]
        t2 = timeit(partial(prime_funct, arg[i/4]), temp, number=1)
        temp = setups[(i+2) % 4]
        t3 = timeit(partial(prime_comprehension, arg[i/4]), temp, number=1)
        t4 = timeit(partial(prime_iter, arg[i/4]), setups[(i+3) % 4], number=1)
        _str = arg[i / 4].__str__() + "\t| " + round(t1, p).__str__()
        _str += "\t| " + round(t2, p).__str__() + "\t| "
        print(_str + round(t3, p).__str__() + "\t|" + round(t4, p).__str__())


print(prime_imp(20))
print(prime_comprehension(20))
print(prime_funct(20))
print(prime_iter(20))
_print(8)
