import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

inp = [tuple(l.split('-')) for l in lines()]
grph = defaultdict(list)
for a,b in inp:
  grph[a].append(b)
  grph[b].append(a)

def small(cv):
  return all('a' <= x <= 'z' for x in cv)

def explore(cv, vis, usedDV):
  if cv == "end":
    return 1
  sm = 0
  for n in grph[cv]:
    if not (small(n) and n in vis):
      if small(n):
        vis.add(n)
      sm += explore(n, vis, usedDV)
      if small(n):
        vis.remove(n)
    if small(n) and n in vis and not usedDV and n != "start":
      sm += explore(n, vis, True)

  return sm

def partA():
  print(explore("start", set(["start"]), True))

def partB():
  print(explore("start", set(["start"]), False))
  pass

partA()
partB()
