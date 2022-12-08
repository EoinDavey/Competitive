import sys
from collections import defaultdict
from functools import reduce
from itertools import product, chain

def lines():
  return [line.strip() for line in sys.stdin]

INP = [[int(x) for x in l] for l in lines()]
H=len(INP)
W=len(INP[0])
valid=lambda x,y: 0 <= x < H and 0 <= y < W

def partA():
  mvs = chain(
    map(lambda x: (x, 0, 0, 1), range(H)),
    map(lambda x: (x, W-1, 0, -1), range(H)),
    map(lambda x: (0, x, 1, 0), range(W)),
    map(lambda x: (H-1, x, -1, 0), range(W)))

  vis = set()
  for (sx, sy, dx, dy) in mvs:
    mx = -1
    cx, cy = sx, sy
    while valid(cx,cy):
      if INP[cx][cy] > mx:
        vis.add((cx, cy))
      mx = max(mx, INP[cx][cy])
      cx += dx
      cy += dy

  print(len(vis))

def partB():
  dsts = defaultdict(lambda: 1)
  mvs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
  for i in range(H):
    for j in range(W):
      for (dx, dy) in mvs:
        dst = 0
        cx, cy = i, j
        while valid(cx+dx, cy+dy):
          cx += dx
          cy += dy
          dst += 1
          if INP[cx][cy] >= INP[i][j]:
            break
        dsts[i,j] *= dst
  print(max(dsts.values()))

partA()
partB()
