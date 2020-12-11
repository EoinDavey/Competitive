import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

mvs = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
ogboard = [list(x) for x in lines()]
H = len(ogboard)
W = len(ogboard[0])

def valid(x, y):
  return 0 <= x < H and 0 <= y < W

def newState(x, y, board, grph, lim):
  cnt = sum([board[nx][ny] == '#' for nx, ny in grph[x, y]])
  if board[x][y] == 'L' and cnt == 0:
    return '#'
  if board[x][y] == '#' and cnt >= lim:
    return 'L'
  return board[x][y]

def solve(grph, lim):
  board = [x.copy() for x in ogboard]
  while True:
    mut = False
    newboard = [x.copy() for x in board]
    for x in range(H):
      for y in range(W):
        if board[x][y] == '.':
          continue
        old = board[x][y]
        new = newState(x, y, board, grph, lim)
        if old != new:
          mut = True
        newboard[x][y] = new
    board = newboard
    if not mut:
      break
  return sum([x.count('#') for x in board])

def partA():
  grph = defaultdict(list)
  for x in range(H):
    for y in range(W):
      if ogboard[x][y] == '.':
        continue
      for dx, dy in mvs:
        nx, ny = x + dx, y + dy
        if not valid(nx, ny):
          continue
        grph[x, y].append((nx, ny))
  print(solve(grph, 4))

def partB():
  grph = defaultdict(list)
  for x in range(H):
    for y in range(W):
      if ogboard[x][y] == '.':
        continue
      for dx, dy in mvs:
        nx, ny = x + dx, y + dy
        while valid(nx, ny):
          if ogboard[nx][ny] != '.':
            grph[x, y].append((nx, ny))
            break
          nx += dx
          ny += dy
  print(solve(grph, 5))

partA()
partB()
