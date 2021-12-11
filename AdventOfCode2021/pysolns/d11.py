import sys
from collections import defaultdict
from itertools import product

mvs = [pt for pt in product(range(-1,2),range(-1,2)) if pt != (0,0)]

def lines():
  return [line.strip() for line in sys.stdin]

obrd = [[int(x) for x in l] for l in lines()]
H = len(obrd)
W = len(obrd[0])
pts = list(product(range(H), range(W)))
obrd = {(x,y): obrd[x][y] for (x,y) in pts}

def valid(pt):
  return 0 <= pt[0] < H and 0 <= pt[1] < W

def ns(pt):
  return [p for p in [(pt[0]+x,pt[1]+y) for (x,y) in mvs] if valid(p)]

def flashprop(b):
  flashed = set()
  toproc = [pt for pt in pts if b[pt] > 9]
  cnt = 0
  while toproc:
    pt = toproc.pop()
    if pt in flashed:
      continue
    cnt += 1
    flashed.add(pt)
    for n in ns(pt):
      b[n] += 1
      if b[n] > 9 and n not in flashed:
        toproc.append(n)
  return cnt

def procstep(b):
  for pt in pts:
    b[pt] += 1
  cnt = flashprop(b)
  for pt in pts:
    if b[pt] > 9:
      b[pt] = 0
  return cnt

def partA():
  brd = {k:v for k,v in obrd.items()}
  sm = 0
  for _ in range(100):
    sm += procstep(brd)
  print(sm)

def partB():
  brd = {k:v for k,v in obrd.items()}
  stp = 0
  while True:
    stp += 1
    procstep(brd)
    if all(v == 0 for v in brd.values()):
      break
  print(stp)

partA()
partB()
