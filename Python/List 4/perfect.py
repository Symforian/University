from timeit import timeit
from math import sqrt, floor


def isPrime(n):
    if n in [2, 3]:
        return True
    for x in range(2, int(floor(sqrt(n)))+1):
        if n % x == 0:
            return False
    return True


def perf_imp(n):
    out = []
    acc = 1
    i = 1
    while True:
        # 2^(i-1) * 2^i -1 == i * acc
        # 2^i -1 -- if prime => prime Mersenne number
        i *= 2
        acc += i
        if isPrime(acc):
            if acc * i > n+1:
                break
            out.append(acc*i)
    return out


def perf_comprehension(n):
    return [x for x in range(1, n+1)
            if sum([y for y in range(1, x) if x % y == 0]) == x]


def perf_funct(n):
    return list(filter(lambda x: x == sum(y for y in range(1, x)
                if x % y == 0), range(1, n+1)))


snip0 = '''
def isPrime(n):
    if n in [2, 3]:
        return True
    for x in range(2, int(floor(sqrt(n)))+1):
        if n % x == 0:
            return False
    return True

def perf_imp(n):
    out = []
    acc = 1
    i = 1
    while True:
        i *= 2
        acc += i
        if isPrime(acc):
            if acc * i > n+1:
                break
            out.append(acc*i)
    return out


perf_imp(1000)
'''
snip1 = '''

def perf_comprehension(n):
    return [x for x in range(1, n+1)
            if sum([y for y in range(1, x) if x % y == 0]) == x]


perf_comprehension(1000)
'''
snip2 = '''
def perf_funct(n):
    return list(filter(lambda x: x == sum(y for y in range(1, x)
                if x % y == 0), range(1, n+1)))


perf_funct(1000)
'''
setup = "from math import sqrt, floor"

print(timeit(snip0, setup, number=100))
print(timeit(snip1, setup, number=100))
print(timeit(snip2, setup, number=100))
print(perf_imp(1000))
print(perf_comprehension(1000))
print(perf_funct(1000))
# print(perf_funct(20))
