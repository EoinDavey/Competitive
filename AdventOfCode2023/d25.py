import sys
import random
from collections import defaultdict
sys.setrecursionlimit(10**4)

INF = 10**9

def lines():
  return [line.strip() for line in sys.stdin]

def bg():
  adj = defaultdict(list)
  for l in lines():
    h, t = l.split(': ')
    for n in t.split(' '):
      adj[h].append(n)
      adj[n].append(h)
  return adj
GRPH = bg()

def ff(u, minE, t, res, vis):
  if u == t:
    return minE
  vis.add(u)
  for i in GRPH[u]:
    if i in vis or res[(u, i)] == 0:
      continue
    f = ff(i, min(minE, res[(u, i)]), t, res, vis)
    if f == 0:
      continue
    res[(u, i)] -= f;
    res[(i, u)] += f;
    return f
  return 0

def fnd(s, res):
  q = [s]
  vis = set([s])
  while q:
    u = q.pop()
    for v in GRPH[u]:
      if v in vis or res[(u, v)] == 0:
        continue
      vis.add(v)
      q.append(v)
  return vis

def partA():
  nodes = list(GRPH.keys())
  while True:
    s = nodes[random.randrange(len(nodes))]
    t = nodes[random.randrange(len(nodes))]
    res = {(u, v): 1 for u in GRPH.keys() for v in GRPH[u]}
    mf = 0
    while True:
      vis = set()
      f = ff(s, INF, t, res, vis)
      if f == 0:
        break;
      mf += f
    if mf == 3:
      st = fnd(s, res)
      print(len(st) * (len(nodes) - len(st)))
      break

def partB():
  pass

partA()
partB()
