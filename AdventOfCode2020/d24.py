import sys
from collections import defaultdict
from functools import reduce

mvs = [(1, -1, 0), (1, 0, -1), (0, 1, -1), (-1, 1, 0), (-1, 0, 1), (0, -1, 1)]

dirs = {
    'nw': 5,
    'ne': 0,
    'sw': 3,
    'se': 2,
    'e': 1,
    'w': 4,
}

def lines():
  return [line.strip() for line in sys.stdin]

def add(a, b):
  return tuple(a + b for a, b in zip(a, b))

def getCmds(line):
  cmds = []
  cr = ""
  for c in line:
    cr += c
    if cr in dirs:
      cmds.append(cr)
      cr = ""
  return cmds

def countNbrs(pos, live):
  return sum(add(pos, x) in live for x in mvs)

def newState(pos, live):
  nbrs = countNbrs(pos, live)
  if pos in live:
    return not (nbrs == 0 or nbrs > 2)
  return nbrs == 2

def qPos(live):
  return list(live) + [add(p, x) for x in mvs for p in live]

def flipped(inp):
  flipCnt = defaultdict(int)
  for cmds in inp:
    pos = reduce(lambda x, y: add(x, mvs[dirs[y]]), cmds, (0, 0, 0))
    flipCnt[pos] += 1
  return [k for k, v in flipCnt.items() if v % 2 == 1]

def partA():
  print(len(flipped(inp)))

def partB():
  live = set(flipped(inp))
  for _ in range(100):
    live = set(p for p in qPos(live) if newState(p, live))
  print(len(live))

inp = [getCmds(x) for x in lines()]

partA()
partB()
