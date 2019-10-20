from math import gcd
from collections import defaultdict

def dfs(ind, g, ls):
    global vis
    if (ind, g) in vis:
        return
    vis.add((ind, g))

    if ind >= len(ls):
        return

    dfs(ind+1, (ls[ind] if g == -1 else gcd(ls[ind], g)), ls)

    if g != -1:
        dfs(ind+1, g, ls)

N, K = [int(x) for x in input().split()]
As = [int(x) for x in input().split()]

unqmp = defaultdict(list)
for i in As:
    if i == 1:
        #TODO
        continue
    p = i
    ps = []
    ps = set()
    while p > 1:
        ps.add(sieve[p])
        p //= sieve[p]
    unq = tuple(sorted(ps))
    unqmp[unq].append(i)

for base, ls in unqmp.items():
    vis = set()
    for i in range(len(ls)):
        dfs(i, -1, ls)
