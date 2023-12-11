import sys
from itertools import product

INF = 10**12

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H = len(INP)
W = len(INP[0])
GALS = [(x, y) for (x, y) in product(range(H), range(W)) if INP[x][y] == '#']

def slv(penalty):
  ers = set(range(H)) - set(x for (x, _) in GALS)
  ecs = set(range(W)) - set(y for (_, y) in GALS)
  sm = 0
  for i, g in enumerate(GALS):
    for h in GALS[i+1:]:
      dx = abs(g[0]-h[0]) + sum(penalty-1 for r in ers if min(h[0],g[0])< r < max(h[0],g[0]))
      dy = abs(g[1]-h[1]) + sum(penalty-1 for c in ecs if min(h[1],g[1])< c < max(h[1],g[1]))
      sm += dx + dy
  return sm

def partA():
  print(slv(2))

def partB():
  print(slv(10**6))

partA()
partB()
