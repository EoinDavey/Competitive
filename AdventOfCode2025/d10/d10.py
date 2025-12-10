import sys
from scipy.optimize import linprog, milp
import re
from collections import deque
from heapq import heappush, heappop, heapify
from math import floor

def lines():
  return [line.strip() for line in sys.stdin]

def parse():
  pat = re.compile(r'^\[([\.#]+)\] ((?:\([0-9,]+\)\s?)+) \{([0-9,]+)\}$')
  out = []
  for ln in lines():
    lts, btns_raw, jltg_raw = pat.match(ln).group(1, 2, 3)
    btns = [[int(y) for y in x[1:-1].split(',')] for x in btns_raw.split(' ')]
    jltg = [int(x) for x in jltg_raw.split(',')]
    out.append((lts, btns, jltg))
  return out

INP = parse()

def shortestPath(lts, btns):
  def press(lts, btn):
    lts = list(lts)
    for x in btn:
      lts[x] = '.' if lts[x] == '#' else '#'
    return tuple(lts)

  w = len(lts)
  T = tuple(lts)
  S = tuple(['.']*w)
  dist = {S: 0}
  q = deque([S])
  while q:
    u = q.popleft()
    du = dist[u]
    if u == T:
      return du
    for btn in btns:
      v = press(u, btn)
      if v in dist:
        continue
      dist[v] = du + 1
      q.append(v)
  return None

def partA():
  return sum(shortestPath(lts, btns) for lts, btns, _ in INP)

def solveILP(btns, jltg):
  n = len(jltg)
  def btn2vec(btn, n):
    v = [0]*n
    for x in btn:
      v[x] = 1
    return v
  mat = [list(x) for x in zip(*[btn2vec(btn, n) for btn in btns])]

  c = [1]*len(btns)

  res = milp(c, integrality = [1]*len(btns), constraints = (mat, jltg, jltg))
  return round(res.fun)

def partB():
  return sum(solveILP(btns, jltg) for _, btns, jltg in INP)

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')

