import sys
from math import floor
from collections import defaultdict
from heapq import heappush, heappop, heapify
from itertools import product

EPS = 1e-6
INF = 10**10

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H = len(INP)
W = len(INP[0])
valid = lambda x, y: 0 <= x < H and 0 <= y < W
BOARD = {(x,y): int(INP[x][y]) for (x,y) in product(range(H), range(W))}

def trnLeft(d):
  c = complex(*d)*1j
  return (floor(c.real + EPS), floor(c.imag + EPS))
trnRight = lambda x: trnLeft(trnLeft(trnLeft(x)))

def nbs(u, d, r, mnt, mxs):
  o = []
  v = (u[0]+d[0], u[1]+d[1])
  if valid(*v) and r + 1 <= mxs:
    o.append((v, d, r+1))
  dl = trnLeft(d)
  v = (u[0]+dl[0], u[1]+dl[1])
  if valid(*v) and r >= mnt:
    o.append((v, dl, 1))
  dr = trnRight(d)
  v = (u[0]+dr[0], u[1]+dr[1])
  if valid(*v) and r >= mnt:
    o.append((v, dr, 1))
  return o

def slv(mnt, mxs):
  dist = defaultdict(lambda: INF)
  q = [(0, (0, 0), (0, 1), 0), (0, (0, 0), (1, 0), 0)]
  heapify(q)
  dist[((0, 0), (0, 1), 0)] = 0
  dist[((0, 0), (1, 0), 0)] = 0
  while q:
    s, u, d, r = heappop(q)
    for (v, nd, nr) in nbs(u, d, r, mnt, mxs):
      ns = s + BOARD[v]
      if ns >= dist[v, nd, nr]:
        continue
      dist[v, nd, nr] = ns
      heappush(q, (ns, v, nd, nr))
  return min(v for (k,v) in dist.items() if k[0] == (H-1, W-1) and k[2] >= mnt)

def partA():
  print(slv(0, 3))

def partB():
  print(slv(4, 10))

partA()
partB()
