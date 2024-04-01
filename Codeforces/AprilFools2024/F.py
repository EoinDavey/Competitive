import sys
from collections import Counter
from itertools import product

grid = [[int(x) for x in input().strip()] for _ in range(21)]
H = len(grid)
W = len(grid[0])
assert(H == 21 and W == 21)

MVS = [(0, 1), (1, 0), (-1, 0), (0, -1)]
valid = lambda x, y: 0 <= x < H and 0 <= y < W

mx = 0
for x, y in product(range(H-3), range(W-3)):
  sm = 0
  for dx, dy in product(range(4), range(4)):
    sm += grid[x+dx][y+dy]
  mx = max(mx, sm)
print(mx)
