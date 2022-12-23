import sys
import re
from collections import defaultdict
from itertools import chain

def lines():
  return [line.rstrip() for line in sys.stdin]
INP = lines()
INF = 10**6
ww = re.findall(r'[0-9]+|L|R', INP[-1])
X = lambda x: int(x.real)
Y = lambda x: int(x.imag)
XY = lambda z: (X(z), Y(z))
trn = lambda z, d: z * [-1j, 1j][d == 'R']

grd = defaultdict(lambda: ' ')
for i, l in enumerate(INP[:-2]):
  for j in range(len(l)):
    grd[j, i] = l[j]

d_mp = {
  (1, 0): 0,
  (-1, 0): 2,
  (0, 1): 1,
  (0, -1): 3,
}

def mv(ps, d, lp):
  z = ps + d
  if grd[XY(z)] != ' ':
    return z
  return lp[XY(ps), XY(d)]

def rn(lp):
  p = INP[0].find('.')
  d = 1
  for w in ww:
    if w in ['L', 'R']:
      d = trn(d, w)
      continue
    for _ in range(int(w)):
      nxt = mv(p, d, lp)
      if grd[XY(nxt)] == '#':
        break
      p = nxt
  return p, d

def partA():
  lp = {}
  rmn = defaultdict(lambda: INF)
  rmx = defaultdict(lambda: -INF)
  cmn = defaultdict(lambda: INF)
  cmx = defaultdict(lambda: -INF)
  for (x, y), v in grd.items():
    if v == ' ':
      continue
    cmn[x] = min(cmn[x], y)
    cmx[x] = max(cmx[x], y)
    rmn[y] = min(rmn[y], x)
    rmx[y] = max(rmx[y], x)

  assert(all(-10**6 < x < 10**6 for x in chain(*[x.values() for x in [cmn, cmx, rmn, rmx]])))
  assert(set(cmn.keys()) == set(cmx.keys()))
  assert(set(rmn.keys()) == set(rmx.keys()))
  for c in cmn.keys():
    mn, mx = cmn[c], cmx[c]
    lp[(c, mn), (0, -1)] = c + mx * (1j)
    lp[(c, mx), (0, 1)] = c + mn * (1j)
  for r in rmn.keys():
    mn, mx = rmn[r], rmx[r]
    lp[(mn, r), (-1, 0)] = mx + r * (1j)
    lp[(mx, r), (1, 0)] = mn + r * (1j)

  p, d = rn(lp)
  print((Y(p)+1) * 1000 + (X(p) + 1) * 4 + d_mp[XY(d)])

def partB():
  pass

partA()
partB()
