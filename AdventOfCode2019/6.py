import sys
from collections import defaultdict

adjList = defaultdict(list)

firstapp = {}
apps = []

for line in sys.stdin:
    a, b = line.strip().split(")")
    adjList[a].append(b)


def trav(u, d):
    firstapp[u] = len(apps)
    apps.append(d)

    for v in adjList[u]:
        trav(v, d + 1)
        apps.append(d)


trav("COM", 0)

L, R = (*sorted([firstapp[x] for x in ["YOU", "SAN"]]),)
md = min(range(L, R + 1), key=lambda x: apps[x])
dist = apps[L] + apps[R] - 2 * apps[md] - 2

print("Part A", sum(map(lambda x: apps[x], firstapp.values())))
print("Part B", dist)
