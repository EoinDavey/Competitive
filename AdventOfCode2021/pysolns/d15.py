import sys
from heapq import heappush, heappop
from collections import defaultdict

INF = 10**9

mvs = [(0,1),(0,-1),(1,0),(-1,0)]

def lines():
  return [line.strip() for line in sys.stdin]

board = [[int(x) for x in l] for l in lines()]
H, W = len(board), len(board[0])

def valid(x, y, h, w):
  return 0 <= x < h and 0 <= y < w

def ns(pt, h, w):
  return [(pt[0] + x, pt[1]+y) for x,y in mvs if valid(pt[0]+x, pt[1]+y, h, w)]

def boardVal(pt):
    bidx = pt[0]//H + pt[1]//W
    bsx, bsy = pt[0] % H, pt[1] % W
    return (board[bsx][bsy] + bidx - 1) % 9 + 1

def dijk(h,w):
  dist = defaultdict(lambda: INF)
  dist[0,0] = 0
  q = [(0, (0,0))]
  while q:
    d, pt = heappop(q)
    if dist[pt] < d:
      continue
    for n in ns(pt, h, w):
      nd = d + boardVal(n)
      if dist[n] > nd:
        dist[n] = nd
        heappush(q, (nd, n))

  return dist[h - 1,w - 1]

def partA():
  print(dijk(H, W))

def partB():
  print(dijk(5*H, 5*W))

partA()
partB()
