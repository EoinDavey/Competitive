import sys
from collections import deque
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

INP = [tuple([int(x) for x in l.split(',')]) for l in lines()]
MVS = [(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0)]

def area(pts):
  tot = 0
  s = set(pts)
  for x in pts:
    f = 6
    for d in MVS:
      n = tuple(x[i]+d[i] for i in [0,1,2])
      if n in s:
        f -= 1
    tot += f
  return tot

def partA():
  print(area(INP))

def partB():
  s = set(INP)
  mxs = [max(INP, key=lambda x: x[i])[i] + 1 for i in range(3)]
  mns = [min(INP, key=lambda x: x[i])[i] - 1 for i in range(3)]
  q = deque([mns])
  ext = set([tuple(mns)])
  while q:
    u = q.popleft()
    for d in MVS:
      n = tuple(u[i]+d[i] for i in [0,1,2])
      if any([n[i] < mns[i] or n[i] > mxs[i] for i in range(3)]):
        continue
      if n in ext or n in s:
        continue
      ext.add(n)
      q.append(n)

  ntr = set()
  for b in product(*[range(mns[i], mxs[i]+1) for i in range(3)]):
    if b not in ext and b not in s:
      ntr.add(b)
  print(area(INP) - area(ntr))

partA()
partB()
