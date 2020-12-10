import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

inp = [int(x) for x in lines()]
sin = [0] + sorted(inp) + [max(inp) + 3]

def partA():
  p = 0
  diffc = defaultdict(int)
  for x in sin:
    diffc[x-p] += 1
    p = x
  print(diffc[1] * diffc[3])

def partB():
  grph = defaultdict(list)
  for x in sin:
    for y in sin:
      if 1 <= x - y <= 3:
        grph[x].append(y)

  mem = {}
  def cnt(u):
    if u == 0:
      return 1
    if not u in mem:
      mem[u] = sum([cnt(v) for v in grph[u]])
    return mem[u]
  print(cnt(sin[-1]))


partA()
partB()
