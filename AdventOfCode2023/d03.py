import sys
from collections import defaultdict
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()

mvs = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]

H = len(INP)
W = len(INP[0])

pwr = defaultdict(int)

for (x,y) in product(range(H),range(W)):
  if INP[x][y] < '0' or INP[x][y] > '9':
    continue
  p = 1
  while y+p < W:
    if INP[x][y+p] < '0' or INP[x][y+p] > '9':
      break
    p += 1
  pwr[x, y] = p-1

visd = set()
def walk(x,y):
  visd.add((x,y))
  for ny in [y+1,y-1]:
    if ny < 0 or ny >= W:
      continue
    if INP[x][ny] < '0' or INP[x][ny] > '9':
      continue
    if (x,ny) in visd:
      continue
    walk(x,ny)

for (x,y) in product(range(H), range(W)):
  if INP[x][y] == '.' or '0' <= INP[x][y] <= '9':
    continue
  for (dx,dy) in mvs:
    if not(0<= x+dx< H and 0<= y+dy < W):
      continue
    if INP[x+dx][y+dy] < '0' or INP[x+dx][y+dy] > '9':
      continue
    walk(x+dx, y+dy)

sm = 0
for (x,y) in product(range(H), range(W)):
  if INP[x][y] < '0' or INP[x][y] > '9':
    continue
  if (x,y) not in visd:
    continue
  sm += int(INP[x][y]) * (10**pwr[(x,y)])
print(sm)

def getVal(x,y,vis):
  v = 0
  i = 0
  while y+i < W:
    if INP[x][y+i] < '0' or INP[x][y+i] > '9':
      break
    vis.add((x,y+i))
    v += int(INP[x][y+i])*(10**pwr[x,y+i])
    i += 1
  i = -1
  while y+i >= 0:
    if INP[x][y+i] < '0' or INP[x][y+i]>'9':
      break
    vis.add((x,y+i))
    v += int(INP[x][y+i])*(10**pwr[x,y+i])
    i -= 1
  return v

pt2 = 0
for (x, y) in product(range(H), range(W)):
  if INP[x][y] != '*':
    continue
  vis = set()
  ls = []
  for (dx, dy) in mvs:
    if not(0<= x+dx< H and 0<= y+dy < W):
      continue
    if INP[x+dx][y+dy] < '0' or INP[x+dx][y+dy] > '9':
      continue
    if (x+dx, y+dy) in vis:
      continue
    ls.append(getVal(x+dx, y+dy, vis))
  if len(ls) == 2:
    pt2 += ls[0] * ls[1]

print(pt2)
