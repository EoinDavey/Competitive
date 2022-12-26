import sys
from itertools import product
from collections import Counter

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H, W = len(INP), len(INP[0])
key = lambda x: (int(x.real), int(x.imag))
MVS = [(0, -1), (0, 1), (-1, 0), (1, 0)]

ds = []
for d in MVS:
  ds.append([d, key(complex(*d) * (1 + 1j)), key(complex(*d) * (1 - 1j))])

ST = {(x, y) for (x, y) in product(range(W), range(H)) if INP[y][x] == '#'}

def f(st):
  mnx = min(st, key=lambda x: x[0])[0]
  mxx = max(st, key=lambda x: x[0])[0]
  mny = min(st, key=lambda x: x[1])[1]
  mxy = max(st, key=lambda x: x[1])[1]
  print((mxx - mnx + 1) * (mxy - mny + 1) - len(st))

def nxt(st, t):
  prop = {}
  for x, y in st:
    ns = [1 for i in range(4) for (dx, dy) in ds[i] if (x + dx, y + dy) in st]
    if sum(ns) == 0:
      continue

    for i in range(4):
      j = (t + i) % 4
      ns = [1 for (dx, dy) in ds[j] if (x + dx, y + dy) in st]
      if sum(ns) == 0:
        prop[x, y] = (x + MVS[j][0], y + MVS[j][1])
        break

  c = Counter(prop.values())
  nst = set()
  for p in st:
    if p not in prop or c[prop[p]] > 1:
      nst.add(p)
      continue
    nst.add(prop[p])

  return nst, t + 1

def partA():
  st = ST.copy()
  t = 0
  for _ in range(10):
    st, t = nxt(st, t)
  f(st)

def partB():
  st = ST.copy()
  t = 0
  while True:
    nst, t = nxt(st, t)
    if st == nst:
      break
    st = nst
  print(t)

partA()
partB()
