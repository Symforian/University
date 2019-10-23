def compress(text):
    n = 0
    prev_letter = ""
    text += "$"
    returntext = text
    for letter in text:
        if (prev_letter == letter):
            n += 1
        elif (n > 0):
            returntext = returntext.replace(prev_letter*(n), str(n+1), 1)
            n = 0
        prev_letter = letter
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
