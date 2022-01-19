import sys
from math import gcd
from functools import reduce

mnps = [
    tuple([int(y.split("=")[1]) for y in x.strip()[1:-1].split(",")]) for x in sys.stdin
]
M = len(mnps)


def ad(x, y):
    return tuple([x + y for (x, y) in zip(x, y)])


def a(mnps):
    mnvs = [(0, 0, 0) for _ in range(M)]
    for _ in range(1000):
        for a in range(M):
            for b in range(a):
                dff = tuple((x > y) - (x < y) for (x, y) in zip(mnps[a], mnps[b]))
                mnvs[a] = ad(mnvs[a], [-x for x in dff])
                mnvs[b] = ad(mnvs[b], dff)
        for k in range(M):
            mnps[k] = ad(mnps[k], mnvs[k])
    return sum([sum(map(abs, x)) * sum(map(abs, y)) for (x, y) in zip(mnvs, mnps)])


def b(mnps):
    tms = [0] * 3
    for i in range(3):
        ps = [x[i] for x in mnps]
        vs = [0] * M
        t = 0
        while True:
            t += 1
            for a in range(M):
                for b in range(a):
                    df = (ps[a] > ps[b]) - (ps[a] < ps[b])
                    vs[a] -= df
                    vs[b] += df
            ps = ad(ps, vs)
            if vs == [0, 0, 0, 0]:
                tms[i] = 2 * t
                break
    return reduce(lambda a, b: (a * b) // gcd(a, b), tms)


print("Part A:", a(mnps[:]))
print("Part B:", b(mnps))
