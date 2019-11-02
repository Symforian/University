from timeit import timeit
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


def prime_comprehension(n):
    return [x for x in range(2, n+1)
            if not any(x % y == 0 for y in range(2, int(floor(sqrt(x)))+1))]


def prime_funct(n):
    return list(filter(lambda x: all(x % y != 0 for y in
                                     range(2, int(floor(sqrt(x)))+1))
                       or x in [2, 3],
                       range(2, n+1)))


snip0 = '''
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


prime_imp(20)
'''
snip1 = '''

def prime_comprehension(n):
    return [x for x in range(2, n+1) if all(x % y != 0 for y in range(2, x))]


prime_comprehension(20)
'''
snip2 = '''
def prime_funct(n):
    return list(filter(lambda x: all(x % y != 0 for y in
                                     range(2, int(floor(sqrt(x)))+1))
                       or x in [2, 3],
                       range(2, n+1)))


prime_funct(20)
'''
setup = "from math import sqrt, floor"

print(timeit(snip0, setup, number=100000))
print(timeit(snip1, setup, number=100000))
print(timeit(snip2, setup, number=100000))
print(prime_imp(20))
print(prime_comprehension(20))
print(prime_funct(20))
