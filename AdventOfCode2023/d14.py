import sys
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H, W = len(INP), len(INP[0])
CYCLES = 1000000000

def slide(r):
  o = []
  c = []
  for x in r:
    if x != '#':
      c.append(x)
      continue
    c.sort(reverse=True)
    o.extend(c)
    o.append('#')
    c = []
  c.sort(reverse=True)
  o.extend(c)
  return tuple(o)

def slideNorth(board):
  cls = [[board[i][j] for i in range(H)] for j in range(W)]
  return tuple(zip(*(slide(c) for c in cls)))

def slideWest(board):
  return tuple(slide(r) for r in board)

def slideSouth(board):
  cls = [[board[i][j] for i in range(H-1, -1, -1)] for j in range(W)]
  return tuple(zip(*(slide(c)[::-1] for c in cls)))

def slideEast(board):
  return tuple(slide(r[::-1])[::-1] for r in board)

def cycle(board):
  return slideEast(slideSouth(slideWest(slideNorth(board))))

def partA():
  s = slideNorth(INP)
  print(sum((H-x) for (x, y) in product(range(H), range(W)) if s[x][y] == 'O'))

def partB():
  seen = {}
  t = 0
  board = tuple(tuple(r) for r in INP)
  while board not in seen:
    seen[board] = t
    t += 1
    board = cycle(board)
  L = t - seen[board]
  diff = CYCLES - t
  for _ in range(diff % L):
    board = cycle(board)
  print(sum((H-x) for (x, y) in product(range(H), range(W)) if board[x][y] == 'O'))

partA()
partB()
