import sys
from collections import defaultdict, deque
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H = len(INP)
W = len(INP[0])
MVS = [(0,1),(1,0),(-1,0),(0,-1)]

INF=10**9
valid=lambda p: 0 <= p[0] < H and 0 <= p[1] < W
def h(x):
  if x == 'S':
    x='a'
  if x == 'E':
    x='z'
  return ord(x) - ord('a')

def run(us):
  dst = defaultdict(lambda: INF)
  e = [(i,j) for (i,j) in product(range(H), range(W)) if INP[i][j] == 'E'][0]

  for u in us:
    dst[u] = 0
  q = deque(us)
  while q:
    (ux, uy) = q.popleft()
    for (dx, dy) in MVS:
      if not valid((ux+dx, uy+dy)):
        continue
      if dst[(ux+dx, uy+dy)] < INF:
        continue
      if h(INP[ux+dx][uy+dy]) > h(INP[ux][uy]) + 1:
        continue
      dst[ux+dx, uy+dy] = dst[ux, uy] + 1
      q.append((ux+dx, uy+dy))
  return dst[e]

def partA():
  s = [(i,j) for (i,j) in product(range(H), range(W)) if INP[i][j] == 'S']
  print(run(s))

def partB():
  us = [(i,j) for (i,j) in product(range(H), range(W)) if h(INP[i][j]) == h('a')]
  print(run(us))

partA()
partB()
