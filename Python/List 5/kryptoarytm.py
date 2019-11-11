from itertools import permutations


def char_list_to_number(char_list, perm):
    temp = map(lambda x: perm.index(x), char_list)
    return reduce(lambda x, y: x * 10 + y, temp)


def symbol_to_function(symbol):
    symbol_function = {
        '+': lambda x, y: x + y,
        '-': lambda x, y: x - y,
        '*': lambda x, y: x * y,
        '/': lambda x, y: x / y,
    }
    return symbol_function[symbol]


def get_letters_perms(args, result):
    letters = reduce(lambda x, y: x + y, args) + result
    letters = list(set([char for char in letters]))
    while len(letters) < 10:
        letters.append("_")
    return list(set(permutations(letters, 10)))


def print_task(args, oper, result):
    leng = max(map(lambda x: len(str(x)), args))
    if leng < len(str(result)):
        leng = len(str(result))
    i = 0
    for arg in args:
        i += 1
        dif = 2 + leng - len(str(arg))
        if i == len(args):
            offset = oper + " " * (dif-1)
        else:
            offset = " "*dif
        print(offset + str(arg))
    print("-" * (2 + leng))
    print(" " * (2 + leng - len(str(result))) + str(result) + "\r\n")


def solve(args, oper, result, number=1):
    print_task(args, oper, result)
    perms = get_letters_perms(args, result)
    args_chars = map(lambda x: [char for char in x], args)
    res_chars = [char for char in result]
    sols = []
    lamb = symbol_to_function(oper)
    for p in perms:
        p_arg = map(lambda x: char_list_to_number(x, p), args_chars)
        p_res = char_list_to_number(res_chars, p)
        if reduce(lamb, p_arg) == p_res:
            sols.append((p_arg, p_res))
            if len(sols) == number:
                break
    [print_task(sol[0], oper, sol[1]) for sol in sols]


solve(["KIOTO", "OSAKA"], '+', "TOKIO")
solve(["KTO", "KOT"], '+', "TOK")
solve(["REBUS", "I"], '*', "SUDOKU")
solve(["ZERO", "ZERO"], '+', "JEDEN")
solve(["GRAD", "DESZCZ"], '+', "STRATA")
solve(["DOM", "DOM"], '*', "MIASTO")
solve(["ROZUM", "DUXO"], '-', "MOXE", 5)
