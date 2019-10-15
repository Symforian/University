def pierwiastek(n):
    k = 0
    c_sum = 0
    for i in range(1, n):
        if c_sum == n:
            return k
        elif c_sum > n:
            return (k-1)
        c_sum += 2*i-1
        k += 1


print(pierwiastek(49))
print(pierwiastek(9))
print(pierwiastek(8))
