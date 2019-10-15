sud = {}


def sudan(n, x, y):
    key = str(n) + " " + str(x) + " " + str(y)
    if(n == 0):
        return x+y
    if(y == 0):
        return x
    if key in sud:
        return sud[key]
    val = sudan(n-1, sudan(n, x, y-1), sudan(n, x, y-1) + y)
    sud[key] = val
    return val


print(
    sudan(0, 1, 1),
    sudan(1, 10, 0),
    sudan(1, 1, 3),
    sudan(1, 1, 4),
    sudan(1, 1, 5),
    sudan(2, 1, 2),
    sudan(1, 14, 14),
    sudan(2, 5, 1)
)


