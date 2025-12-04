import sys
from itertools import product

MVS = [mv for mv in product([-1, 0, 1], [-1, 0, 1]) if mv != (0, 0)]

def lines():
  return [line.strip() for line in sys.stdin]

GRID = [[c for c in x] for x in lines()]
H = len(GRID)
W = len(GRID[0])

def nbrs(r, c):
  for dr, dc in MVS:
    nr, nc = r + dr, c + dc
    if not (0 <= nr < H and 0 <= nc < W):
      continue
    if GRID[nr][nc] != '@':
      continue
    yield (nr, nc)

def nbr_cnt(r, c):
  return len(list(nbrs(r, c)))

def partA():
  return len([(r, c) for r, c in product(range(H), range(W)) if GRID[r][c] == '@' and nbr_cnt(r, c) < 4])

def partB():
  deg = [[nbr_cnt(r, c) for c in range(W)] for r in range(H)]
  stck = [(r, c) for r, c in product(range(H), range(W)) if GRID[r][c] == '@' and deg[r][c] < 4]
  seen = set(stck)
  while stck:
    r, c = stck.pop()
    for nr, nc in nbrs(r, c):
      deg[nr][nc] -= 1
      if deg[nr][nc] >= 4:
        continue
      if (nr, nc) in seen:
        continue
      seen.add((nr, nc))
      stck.append((nr, nc))
  return len(seen)

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
