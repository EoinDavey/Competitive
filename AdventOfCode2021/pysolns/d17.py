import sys
from collections import defaultdict
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

xrng, yrng = [[int(y) for y in x.split('=')[1].split('..')] for x in lines()[0].replace(',','').split()[2:]]

def partA():
  dy = abs(yrng[0]) - 1
  print("Part 1:", (dy*(dy+1)) // 2)

def findTs(rng, cond, dmin, dmax):
  ts = []
  for d in range(dmin, dmax+1):
    od = d
    v = 0
    t = 0
    while cond(d):
      v += d
      t += 1
      d -= 1
      if rng[0] <= v <= rng[1]:
        ts.append((t, od, d))
  return ts

def partB():
  tmap = defaultdict(lambda: [[],[]])

  xs = findTs(xrng, lambda dx: dx != 0, 1, xrng[1])
  for (t, x, _) in xs:
    tmap[t][0].append(x)

  xstops = [(t, x) for (t, x, dx) in xs if dx == 0]

  ys = findTs(yrng, lambda dy: dy >= yrng[0], yrng[0], abs(yrng[0]))
  for (t, y, _) in ys:
    tmap[t][1].append(y)

  for t in tmap.keys():
    for (tx, x) in xstops:
      if t >= tx:
        tmap[t][0].append(x)

  s = set()
  for t in tmap.keys():
    xs, ys = tmap[t]
    s |= set(pr for pr in product(xs,ys))
  print("Part 2:", len(s))


partA()
partB()
