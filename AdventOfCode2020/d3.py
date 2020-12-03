import sys
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

board = lines()
assert(all(map(lambda x: len(x) == len(board[0]), board)))

def get(x, y):
  return board[x][y % len(board[0])]

def slopeHits(dx, dy):
  x, y = 0, 0
  cnt = 0
  while x < len(board):
    if get(x,  y) == '#':
      cnt += 1
    x, y = x + dx, y + dy
  return cnt

def partA():
  print(slopeHits(1, 3))

def partB():
  slopes = [(1, 1), (1, 3), (1, 5), (1, 7), (2, 1)]
  hits = [slopeHits(x, y) for (x, y) in slopes]
  print(reduce(lambda x, y: x * y, hits))

partA()
partB()
