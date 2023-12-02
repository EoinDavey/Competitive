import sys
from collections import defaultdict
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]
def read():
  out = []
  for l in lines():
    g, r = l.split(': ')
    _, gid_s = g.split(' ')
    gid = int(gid_s)
    turns = [t.split(', ') for t in r.split('; ')]
    ts = [dict([(lambda y: (y[1],int(y[0])))(x.split(' ')) for x in t]) for t in turns]
    out.append((gid, ts))
  return out

INP = read()

def partA():
  lim = {'red': 12, 'green': 13, 'blue': 14}
  sm = 0
  for (gid, ts) in INP:
    if all(lim[k] >= v for t in ts for (k,v) in t.items()):
      sm += gid
  print(sm)

def partB():
  sm = 0
  for (_, ts) in INP:
    lms = defaultdict(int)
    for t in ts:
      for (k,v) in t.items():
        lms[k] = max(lms[k], v)
    sm += reduce(lambda x,y: x*y, lms.values(), 1)
  print(sm)

partA()
partB()
