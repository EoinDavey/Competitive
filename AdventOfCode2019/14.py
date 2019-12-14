import sys
from collections import defaultdict

grph = [line.strip().replace(',','').replace('=> ','').split(' ') for line in sys.stdin]
adjList = defaultdict(list)
amnts = defaultdict(int)
for g in grph:
    amnts[g[-1]] = int(g[-2])
    for i in range(0, len(g) - 2, 2):
        adjList[g[-1]].append((int(g[i]), g[i+1]))

vis = set()
top = []
def trav(u):
    vis.add(u)
    for v in adjList[u]:
        if v[1] not in vis:
            trav(v[1])
    top.append(u)
trav('FUEL')
top.reverse()

def solve(tgt):
    reqs = defaultdict(int)
    reqs['FUEL'] = tgt
    for x in top:
        req = reqs[x]
        if x == 'ORE':
            return req
        amnt = amnts[x]
        tms = (req + amnt-1)//amnt
        for (a, b) in adjList[x]:
            reqs[b] += tms * a

TR = 10**12
L ,R = 0, TR
while L < R:
    md = (L+R+1)//2
    v = solve(md)
    if v > TR:
        R = md - 1
    else:
        L = md

print('Part A:',solve(1))
print('Part B:', L)
