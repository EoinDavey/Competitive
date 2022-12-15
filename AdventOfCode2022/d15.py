import sys, re
from collections import namedtuple, defaultdict
S = namedtuple('S', ['x', 'y', 'nbx', 'nby'])

def lines():
  return [line.strip() for line in sys.stdin]
INP = [S(*map(int, re.findall(r'-?[0-9]+', l))) for l in lines()]

def solveRow(y):
  ivls = []

  blckd = set()
  for s in INP:
    if s.y == y:
      blckd.add(s.x)
    if s.nby == y:
      blckd.add(s.nbx)

  blckd = list(sorted(blckd))
  for s in INP:
    rad = abs(s.x - s.nbx) + abs(s.y - s.nby)
    r = rad - abs(s.y - y)
    ub = r + s.x # x - s.x <= r: x <= r + s.x
    lb = s.x - r # s.x - x <= r: s.x - r <= x
    if ub < lb:
      continue
    for b in blckd:
      if lb <= b <= ub:
        ivls.append((lb, b-1))
        lb = b+1
    ivls.append((lb, ub))

  ivls.sort()
  u = []
  l, r = ivls[0]
  for (li, ri) in ivls[1:]:
    if li > r+1:
      u.append((l, r))
      l, r = li, ri
    r = max(r, ri)
  u.append((l, r))
  return u

def partA():
  ivls = solveRow(2000000)
  print(sum(r-l+1 for (l, r) in ivls))

def partB():
  C = 4000000

  for y in range(C+1):
    ivls = [(-10**6, -1), (C+1, 10**6)]
    for s in INP:
      rad = abs(s.x - s.nbx) + abs(s.y - s.nby)
      r = rad - abs(s.y - y)
      ub = r + s.x # x - s.x <= r: x <= r + s.x
      lb = s.x - r # s.x - x <= r: s.x - r <= x
      if ub < lb:
        continue
      ivls.append((lb, ub))

    ivls.sort()
    u = []
    l, r = ivls[0]
    for (li, ri) in ivls[1:]:
      if li > r + 1:
        u.append((l, r))
        l, r = li, ri
      r = max(r, ri)
    u.append((l, r))
    if len(u) > 1:
      print(C*(u[0][1]+1) + y)
      break

partA()
partB()
