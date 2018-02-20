from functools import reduce
s = input()

def f(xs,a):
    if len(xs) < 1:
        return [[a]]
    if xs[-1][-1] <= a:
        return xs[:-1] + [xs[-1] + [a]]
    return xs + [[a]]

print(max(map(len,reduce(f,s,[]))))
