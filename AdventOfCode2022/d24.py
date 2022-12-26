import sys
from collections import deque

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H, W = len(INP), len(INP[0])
MVS = [(1, 0), (0, 1), (-1, 0), (0, -1), (0, 0)]
BS = []
for i, l in enumerate(INP):
  for j, c in enumerate(l):
    if INP[i][j] in '<>^v':
      BS.append(((i, j), c))
S = (0, INP[0].find('.'))
T = (H - 1, INP[-1].find('.'))

def p(b, t):
  (x, y), c = b
  dx, dy = {'>': (0, 1), '<': (0, -1), '^': (-1, 0), 'v': (1, 0)}[c]
  nx = 1 + (((x - 1) + t * dx) % (H - 2))
  ny = 1 + (((y - 1) + t * dy) % (W - 2))
  return nx, ny

memo = {}
def blckd(t):
  if t in memo:
    return memo[t]
  s = set()
  for b in BS:
    s.add(p(b, t))
  memo[t] = s
  return s

def slv(S, T, t=0):
  vis = set()
  q = deque([(S, t)])
  vis.add((S, t))
  while q:
    (x, y), t = q.popleft()
    if (x, y) == T:
      return t
    for (dx, dy) in MVS:
      n = (x + dx, y + dy)
      st = (n, t + 1)
      if st in vis:
        continue
      if not (0 <= n[0] < H and 0 <= n[1] < W):
        continue
      if INP[n[0]][n[1]] == '#':
        continue
      if n in blckd(t + 1):
        continue
      vis.add(st)
      q.append(st)

def partA():
  print(slv(S, T, 0))

def partB():
  print(slv(S, T, slv(T, S, slv(S, T, 0))))

partA()
partB()
