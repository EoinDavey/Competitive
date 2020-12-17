import sys
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

inb = lines()
H = len(inb)
W = len(inb[0])

mvs3 = [(x,y,z) for x, y, z in product(*([[-1, 0, 1]]*3)) if x or y or z]
mvs4 = [(w,x,y,z) for w, x, y, z in product(*([[-1, 0, 1]]*4)) if x or y or z or w]

def add(a, b):
  return (a[0] + b[0], a[1] + b[1], a[2] + b[2]) + ((a[3] + b[3],) if len(a) == 4 else ())

def cntNbs(pos, board, mvs):
  return sum([add(pos, d) in board for d in mvs])

def newState(pos, board, mvs):
  nbs = cntNbs(pos, board, mvs)
  if pos in board:
    return 2 <= nbs <= 3
  return nbs == 3

def qPos(board, mvs):
  return list(board) + [add(p, d) for d in mvs for p in board]

def solve(board, mvs):
  for _ in range(6):
    board = set([pos for pos in qPos(board, mvs) if newState(pos, board, mvs)])
  return len(board)

def partA():
  board = {(0, x, y) for x, y in product(range(H), range(W)) if inb[x][y] == '#'}
  print(solve(board, mvs3))

def partB():
  board = {(0, 0, x, y) for x, y in product(range(H), range(W)) if inb[x][y] == '#'}
  print(solve(board, mvs4))

partA()
partB()
