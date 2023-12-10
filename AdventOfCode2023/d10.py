import sys
from itertools import product
from collections import defaultdict, deque

def lines():
  return [line.strip() for line in sys.stdin]
INP = [list(l) for l in lines()]
H = len(INP)
W = len(INP[0])
valid = lambda x, y: 0 <= x < H and 0 <= y < W

con = {
  (0, 1): (['S', '-', 'F', 'L'], ['-', 'J', '7', 'S']),
  (0, -1): (['S', '-', 'J', '7'], ['-', 'L', 'F', 'S']),
  (1, 0): (['S', '|', '7', 'F'], ['|', 'L', 'J', 'S']),
  (-1, 0): (['S', '|', 'L', 'J'], ['|', '7', 'F', 'S']),
}

def bldGrph():
  grph = defaultdict(list)
  for (x, y) in product(range(H), range(W)):
    for ((dx, dy), (src, dest)) in con.items():
      if INP[x][y] not in src:
        continue
      nx, ny = x + dx, y + dy
      if not valid(nx, ny):
        continue
      if INP[nx][ny] not in dest:
        continue
      grph[x, y].append((nx,ny))
  return grph

GRPH = bldGrph()
SPOS = [p for p in product(range(H), range(W)) if INP[p[0]][p[1]] == 'S'][0]

s = set('JLF7')
for (nx, ny) in GRPH[SPOS]:
  dx, dy = nx - SPOS[0], ny - SPOS[1]
  src, _ = con[dx, dy]
  s = s & set(src)
INP[SPOS[0]][SPOS[1]] = list(s)[0]

def partA():
  dst = {}
  st = deque([SPOS])
  dst[SPOS] = 0
  while st:
    v = st.popleft()
    for u in GRPH[v]:
      if u in dst:
        continue
      dst[u] = dst[v] + 1
      st.append(u)
  print(max(dst.values()))

def partB():
  mrkLoop = set()
  st = deque([SPOS])
  mrkLoop.add(SPOS)
  while st:
    v = st.popleft()
    for u in GRPH[v]:
      if u in mrkLoop:
        continue
      mrkLoop.add(u)
      st.append(u)

  val = defaultdict(int)
  for (x, y) in mrkLoop:
    if INP[x][y] == '|':
      val[x, y] = 1
      continue

    if INP[x][y] not in ['F', 'L']:
      continue
    wy = y + 1
    while INP[x][wy] == '-':
      wy += 1
    if (INP[x][y], INP[x][wy]) in [('F', 'J'), ('L', '7')]:
      val[x, y] = 1

  sm = 0
  for (x, y) in product(range(H), range(W)):
    if (x, y) in mrkLoop:
      continue
    py = y
    c = 0
    while valid(x, py):
      py += 1
      c += val[x, py]
    sm += 1 if c % 2 == 1 else 0

  print(sm)

partA()
partB()
