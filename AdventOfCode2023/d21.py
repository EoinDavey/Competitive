import sys
from itertools import product, chain
from collections import defaultdict, deque
from functools import reduce, lru_cache
from math import ceil

STEPS = 26501365 

def lines():
  return [line.strip() for line in sys.stdin]
BOARD = lines()
H = len(BOARD)
W = len(BOARD[0])
S = [(x,y) for (x, y) in product(range(H), range(W)) if BOARD[x][y] == 'S'][0]
valid = lambda x, y: 0 <= x < H and 0 <= y < W

MVS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
def buildGraph():
  grph = defaultdict(list)
  for x, y, (dx, dy) in product(range(H), range(W), MVS):
    if BOARD[x][y] == '#':
      continue
    nx, ny = x + dx, y + dy
    if not valid(nx, ny) or BOARD[nx][ny] == '#':
      continue
    grph[x, y].append((nx, ny))
  return grph

GRPH = buildGraph()

# no trapped vertices (keys at least)
def checkTrap():
  assert(BOARD[0][0] == '.')
  q = deque([(0,0)])
  vis=set()
  vis.add((0,0))
  while q:
    u = q.popleft()
    for n in GRPH[u]:
      if n in vis:
        continue
      vis.add(n)
      q.append(n)
  assert(len(vis) == len(GRPH.keys()))

def rbs():
  o = [0, 0]
  for k in GRPH.keys():
    o[(k[0] + k[1]) % 2] += 1
  return o

@lru_cache(maxsize=None)
def dists(p):
  q = deque([p])
  d = {}
  d[p] = 0
  while q:
    u = q.popleft()
    for n in GRPH[u]:
      if n in d:
        continue
      d[n] = d[u] + 1
      q.append(n)
  return d

@lru_cache(maxsize=None)
def localReach(p, stps):
  assert(stps <= H+W)
  return sum(1 for v in dists(p).values() if v <= stps and (v % 2) == (stps % 2))

def maxEdgeDist():
  return max(max(dists(p).values()) for p in [
    (0, 0), (0, W-1), (H-1, 0), (H-1, W-1), (0, W//2), (H-1, W//2), (H//2, 0), (H//2, W-1)])

def checkCleanLine():
  assert(all(BOARD[S[0]][j] != '#' for j in range(W)))
  assert(all(BOARD[i][S[1]] != '#' for i in range(H)))

def checkMED():
  med = maxEdgeDist()
  c2c = H+W - 2
  assert(med == c2c)
  return med

def localClosest(bx, by):
  if bx == 0 and by == 0:
    return S
  if bx == 0 and by > 0:
    return (H//2, 0)
  if bx == 0 and by < 0:
    return (H//2, W-1)
  assert(bx != 0)
  if bx < 0 and by == 0:
    return (H-1, W//2)
  if bx < 0 and by < 0:
    return (H-1, W-1)
  if bx < 0 and by > 0:
    return (H-1, 0)
  assert(bx > 0)
  if by == 0:
    return (0, W//2)
  if by < 0:
    return (0, W-1)
  if by > 0:
    return (0, 0)

def loc2Glob(l, b):
  gx = b[0]*H + l[0]
  gy = b[1]*H + l[1]
  return gx, gy

def partA():
  print(localReach(S, 64))

def partB():
  assert(H == W)
  assert(H % 2 == 1)
  checkTrap()
  checkCleanLine()
  med = checkMED()
  reds, blacks = rbs()
  k = ceil(STEPS / W)

  osum = 0
  for (hgtinit, hgtinc) in [(0, -1), (1, 1)]:
    hgt = hgtinit
    lu = [-k, k]
    while True:
      for i, d in [(0, 1), (1, -1)]:
        lu[i] -= 2*d
        while lu[i] != 0:
          lx, ly = localClosest(hgt, lu[i])
          gx, gy = loc2Glob((lx, ly), (hgt, lu[i]))
          d2c = abs(S[0]-gx) + abs(S[1]-gy)
          if d2c + med <= STEPS:
            break
          if d2c > STEPS:
            lu[i] += d
            continue
          ds = localReach((lx, ly), STEPS-d2c)
          osum += ds
          lu[i] += d

        lcont = (abs(lu[i])//2)*(reds+blacks)
        if lu[i] % 2 == 1:
          lcont += blacks if STEPS % 2 == hgt % 2 else reds
        assert(lu[i] != 0 or lcont == 0)
        osum += lcont

      olx, oly = localClosest(hgt, 0)
      ogx, ogy = loc2Glob((olx, oly), (hgt, 0))
      od2c = abs(S[0]-ogx) + abs(S[1]-ogy)
      ocont = localReach((olx, oly), STEPS-od2c) if STEPS-od2c <= med else (reds if STEPS % 2 == hgt % 2 else blacks)
      osum += ocont
      if ocont == 0:
        break
      hgt += hgtinc
  print(osum)

partA()
partB()
