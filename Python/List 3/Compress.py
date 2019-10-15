def compress(text):
    n = 0
    pl = ""
    text += "$"
    returntext = text
    for l in text:
        if (pl == l):
            n += 1
        elif (n > 0):
            n += 1
            returntext = returntext.replace(pl*(n-1), str(n), 1)
            n = 0
        pl = l
    return returntext[0:-1]


def decompress(text):
    n = 0
    returntext = text
    for l in text:
        if(n > 0):
            if (l.isdigit()):
                n = n * 10 + int(l)
            else:
                returntext = returntext.replace(str(n), l*(n-1), 1)
                n = 0
        elif (l.isdigit()):
            n = int(l)
    return returntext


print(compress("suuuuper"))
print(decompress("s4uper"))
print(compress("aaaaaaaaaa"))
print(decompress("10a"))
