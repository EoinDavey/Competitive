import sys
from itertools import product
from collections import Counter

mvs = [(0,1),(0,-1),(1,0),(-1,0)]

def lines():
  return [line.strip() for line in sys.stdin]

inp = [[int(x) for x in l] for l in lines()]
H, W = len(inp), len(inp[0])
board = dict([[(x,y), inp[x][y]] for x,y in product(range(H), range(W))])

def valid(t):
  return 0 <= t[0] < H and 0 <= t[1] < W

def ns(p):
  return [(p[0]+dx,p[1]+dy) for (dx,dy) in mvs if valid((p[0]+dx,p[1]+dy))]

def partA():
  print(sum([board[p] + 1 for p in product(range(H), range(W))
    if all([board[np] > board[p] for np in ns(p)])]))

def partB():
  colour = {}
  def col(p, c):
    for n in ns(p):
      if n not in colour and board[n] < 9:
        colour[n] = c
        col(n, c)

  for pt in product(range(H),range(W)):
    if pt not in colour and board[pt] < 9:
      col(pt, len(colour))
  a,b,c = [v for _,v in Counter(colour.values()).most_common(3)]
  print(a*b*c)

partA()
partB()
