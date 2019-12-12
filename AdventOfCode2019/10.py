import sys, math as m, itertools as i

l, F, e = len, filter, enumerate
S = "Part"
s = [(x[0], y[0]) for x in e(sys.stdin) for y in e(x[1].strip()) if y[1] == "#"]


def R(a, b):
    g = m.gcd(a, b)
    return m.atan2((-1.0 * b) / g, a / g)


M, X, Y = max(
    [
        (l(set([R(a - x, b - y) for (a, b) in s if (a, b) != (x, y)])), x, y)
        for (x, y) in s
    ]
)
f = lambda x: R(x[0] - X, x[1] - Y)
T = list(
    F(
        lambda x: x,
        i.chain.from_iterable(
            i.zip_longest(
                *[
                    list(x[1])
                    for x in i.groupby(
                        sorted(F(lambda a: a != (X, Y), s), key=f), key=f
                    )
                ]
            )
        ),
    )
)[199]
print(S, "A", M, S, "B", T[1] * 100 + T[0])
