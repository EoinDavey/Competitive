import sys
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

GRID = lines()
H = len(GRID)
W = len(GRID[0])
S_POS = [(x, y) for (x, y) in product(range(H), range(W)) if GRID[x][y] == 'S'][0]

def partA():
  seen = set()
  def f(pos):
    x, y = pos
    if GRID[x][y] == '^':
      splits = 1
      for nbr in [(x + 1, y - 1), (x + 1, y + 1)]:
        if nbr in seen:
          continue
        if not (0 <= nbr[0] < H and 0 <= nbr[0] < W):
          continue
        seen.add(nbr)
        splits += f(nbr)
      return splits

    if (x + 1, y) in seen or not (0 <= x + 1 < H):
      return 0

    seen.add((x + 1, y))
    return f((x + 1, y))

  return f(S_POS)

def partB():
  memo = dict()
  def f(pos):
    if pos in memo:
      return memo[pos]
    x, y = pos

    if not (0 <= x + 1 < H):
      memo[pos] = 1
      return 1

    if GRID[x][y] == '^':
      res = sum(f(nbr) for nbr in [(x + 1, y - 1), (x + 1, y + 1)] if 0 <= nbr[1] < W)
      memo[pos] = res
      return res

    ans = f((x + 1, y))
    memo[pos] = ans
    return ans

  return f(S_POS)

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
