import sys
from collections import defaultdict, deque
from itertools import product
from functools import reduce, lru_cache
from heapq import heappush, heappop

def lines():
  return [line.strip() for line in sys.stdin]
INP = [tuple(tuple(int(y) for y in x.split(',')) for x in l.split('~')) for l in lines()]

def shiftDown(cb):
  return ((cb[0][0], cb[0][1], cb[0][2] - 1), (cb[1][0], cb[1][1], cb[1][2] - 1))

def clmp(x):
  return abs(x)//x if x != 0 else 0

@lru_cache(maxsize=None)
def getBlcks(cb):
  cbs, cbe = cb
  dlt = [cbe[i]-cbs[i] for i in range(3)]
  dlt = tuple(clmp(x) for x in dlt)
  blcks = []
  w = cbs
  while True:
    blcks.append(w)
    if w == cbe:
      break
    w = (w[0]+dlt[0], w[1]+dlt[1], w[2]+dlt[2])
  return blcks

def floor(cb):
  return min(cb[0][2], cb[1][2])

def upgrph(cbs):
  adj = defaultdict(list)
  blcks = [getBlcks(cbs[i]) for i in range(len(cbs))]
  for i in range(len(cbs)):
    ubs = set(blcks[i])
    for j in range(len(cbs)):
      if i == j:
        continue
      if any((lb[0], lb[1], lb[2] + 1) in ubs for lb in blcks[j]):
        adj[j].append(i)
  return adj

def settle():
  zord = sorted(INP, key=floor)
  occ = set()
  setld = []
  for cb in zord:
    while True:
      if floor(cb) == 1:
        break
      dwn = shiftDown(cb)
      if any(b in occ for b in getBlcks(dwn)):
         break
      cb = dwn
    occ.update(getBlcks(cb))
    setld.append(cb)
  return setld

def calcWays2Ground(setld, grph):
  grnd = [i for i in range(len(setld)) if floor(setld[i]) == 1]
  ways = defaultdict(int)
  ways.update({i: 1 for i in grnd})
  upord = sorted(range(len(setld)), key=lambda i: floor(setld[i]))
  for u in upord:
    for n in grph[u]:
      ways[n] += ways[u]
  return ways

def partA():
  setld = settle()
  grph = upgrph(setld)
  ways = calcWays2Ground(setld, grph)

  print(sum(1 for i in range(len(setld)) if all(ways[j] > ways[i] for j in grph[i])))

def partB():
  setld = settle()
  grph = upgrph(setld)
  ways = calcWays2Ground(setld, grph)

  sm = 0
  for i in range(len(setld)):
    q = [(floor(setld[i]), i)]
    vis = set([i])
    deadcnt = defaultdict(int)
    deadcnt[i] = ways[i]
    cnt = 0
    while q:
      _, u = heappop(q)
      if ways[u] != deadcnt[u]:
        continue
      cnt += 1
      for n in grph[u]:
        deadcnt[n] += deadcnt[u]
        if n not in vis:
          vis.add(n)
          heappush(q, (floor(setld[n]), n))
    if cnt > 1:
      sm += cnt - 1
  print(sm)

def partBMrk2():
  setld = settle()
  grph = upgrph(setld)
  ways = calcWays2Ground(setld, grph)

  sm = 0
  dgrph = defaultdict(list)
  for i in range(len(setld)):
    for j in grph[i]:
      dgrph[j].append(i)

  for i in range(len(setld)):
    wdwn = defaultdict(int)
    wdwn[i] = 1
    q = [(-floor(setld[i]), i)]
    while q:
      _, u = heappop(q)
      for n in dgrph[u]:
        if n not in wdwn:
          heappush(q, (-floor(setld[n]), n))
        wdwn[n] += wdwn[u]
    cnt = 0
    for u in wdwn.keys():
      if wdwn[u] * ways[u] == ways[i]:
        cnt += 1
    sm += cnt-1
  print(sm)

partA()
partB()
partBMrk2()
