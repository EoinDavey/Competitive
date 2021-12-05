import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

inp = [[[int(a) for a in x.split(',')] for x in l.split(' -> ')] for l in lines()]

def sign(x):
  return 1 if x > 0 else 0 if x == 0 else -1

def countInters(ls):
  hit = defaultdict(int)
  for a,b in ls:
    v = (sign(b[0]-a[0]), sign(b[1]-a[1]))
    pt = (a[0], a[1])
    while pt[0] != b[0] or pt[1] != b[1]:
      hit[pt] += 1
      pt = (pt[0] + v[0], pt[1] + v[1])
    hit[pt] += 1
  return len(list(filter(lambda x: x[1] > 1, hit.items())))

def partA():
  hvLs = list(filter(lambda l: l[0][0] == l[1][0] or l[0][1] == l[1][1], inp))
  print(countInters(hvLs))

def partB():
  print(countInters(inp))

partA()
partB()
