import sys
from itertools import product
from collections import defaultdict, Counter

INF = 10**9

def lines():
  return [line.strip() for line in sys.stdin]
BOARD = lines()
H = len(BOARD)
W = len(BOARD[0])
valid = lambda x, y: 0 <= x < H and 0 <= y < W
MVS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

dirs = {
  '>': (0, 1),
  '<': (0, -1),
  'v': (1, 0),
  '^': (-1, 0),
}

def bldGrph():
  grph = defaultdict(list)
  for x, y in product(range(H), range(W)):
    if BOARD[x][y] != '.':
      continue
    for (dx, dy) in MVS:
      nx, ny = x + dx, y + dy
      if not valid(nx, ny) or BOARD[nx][ny] != '.':
        continue
      grph[x, y].append((nx, ny))

  for x, y in product(range(H), range(W)):
    if BOARD[x][y] not in '<>^v':
      continue
    dx, dy = dirs[BOARD[x][y]]
    grph[x-dx, y-dy].append((x, y))
    grph[x, y].append((x+dx, y+dy))
  assert(all(len(v) <= 2 for v in grph.values()))
  return grph

GRPH = bldGrph()

def colr():
  c = 1
  cols = {}
  for k in GRPH.keys():
    if BOARD[k[0]][k[1]] != '.':
      continue
    if k in cols:
      continue
    q = [k]
    cols[k] = c
    while q:
      u = q.pop()
      for n in GRPH[u]:
        if BOARD[n[0]][n[1]] != '.' or n in cols:
          continue
        cols[n] = c
        q.append(n)
    c += 1
  return cols

def topsort(grph, revgrph):
  indeg = {c: len(revgrph[c]) for c in grph.keys()}
  tord = []
  tidx = {}
  q = [c for c in grph.keys() if indeg[c] == 0]
  while q:
    u = q.pop()
    tidx[u] = len(tord)
    tord.append(u)
    for m in grph[u]:
      indeg[m] -= 1
      if indeg[m] == 0:
        q.append(m)
  return tord, tidx

def partA():
  colmp = colr()
  colcnt = Counter(colmp.values())
  cols = list(set(colmp.values()))
  cgrph = {c: [] for c in cols}
  cgrphrev = {c: [] for c in cols}
  for x, y in product(range(H), range(W)):
    if BOARD[x][y] in '.#':
      continue
    dx, dy = dirs[BOARD[x][y]]
    cb = colmp[x-dx, y-dy]
    cf = colmp[x+dx, y+dy]
    cgrph[cb].append(cf)
    cgrphrev[cf].append(cb)
  scol = colmp[0, 1]
  ecol = colmp[H-1, W-2]
  tsort, tidx = topsort(cgrph, cgrphrev)
  lngst = defaultdict(lambda: -INF)
  lngst[scol] = colcnt[scol]
  for c in tsort[1:]:
    pmx = max((lngst[p] for p in cgrphrev[c]), default=-INF)
    lngst[c] = 1 + pmx + colcnt[c]
  print(lngst[ecol] - 1)

def findLong(u, grph, vis, colcnt, tgt):
  if u == tgt:
    return colcnt[tgt]
  wgt = colcnt[u]
  mx = -INF
  for v in grph[u]:
    if v in vis:
      continue
    vis.add(v)
    mx = max(mx, 1 + wgt + findLong(v, grph, vis, colcnt, tgt))
    vis.remove(v)
  return mx

def partB():
  colmp = colr()
  colcnt = Counter(colmp.values())
  cols = list(set(colmp.values()))
  cgrph = {c: [] for c in cols}
  for x, y in product(range(H), range(W)):
    if BOARD[x][y] in '.#':
      continue
    dx, dy = dirs[BOARD[x][y]]
    cb = colmp[x-dx, y-dy]
    cf = colmp[x+dx, y+dy]
    cgrph[cb].append(cf)
    cgrph[cf].append(cb)
  scol = colmp[0, 1]
  ecol = colmp[H-1, W-2]
  print(findLong(scol, cgrph, set([scol]), colcnt, ecol) - 1)

partA()
partB()
