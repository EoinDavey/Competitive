import sys
from itertools import product
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

board = [list(l) for l in lines()]
H, W = len(board), len(board[0])
board = {(x,y): board[x][y] for x, y in product(range(H), range(W))}

def step():
  mvd = False
  nb = defaultdict(lambda: '.')
  for x, y in product(range(H), range(W)):
    nxt = (y + 1) % W
    if board[x, y] == '.':
      continue
    if board[x, y] != '>' or board[x, nxt] != '.':
      nb[x, y] = board[x, y]
      continue
    nb[x, y], nb[x, nxt] = '.', '>'
    mvd = True

  nb2 = defaultdict(lambda: '.')
  for x, y in product(range(H), range(W)):
    nxt = (x + 1) % H
    if nb[x, y] == '.':
      continue
    if nb[x, y] != 'v' or nb[nxt, y] != '.':
      nb2[x, y] = nb[x, y]
      continue
    nb2[x, y], nb2[nxt, y] = '.', 'v'
    mvd = True

  return nb2, mvd

def partA():
  global board
  cnt = 0
  while True:
    cnt += 1
    board, mvd = step()
    if not mvd:
      print(cnt)
      break

def partB():
  pass

partA()
partB()
