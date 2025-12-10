import sys
import re
from collections import deque
from heapq import heappush, heappop, heapify

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

def press(lts, btn):
  lts = list(lts)
  for x in btn:
    lts[x] = '.' if lts[x] == '#' else '#'
  return tuple(lts)

def shortestPath(lts, btns):
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

def aStar(btns, jltg):
  w = len(jltg)
  T = tuple(jltg)
  S = tuple([0]*w)
  mx_jump = max(len(btn) for btn in btns)

  def pressJ(u, btn):
    ls = list(u)
    for x in btn:
      ls[x] += 1
    return tuple(ls)

  def h(u):
    return sum(T[i] - u[i] for i in range(w)) / mx_jump

  def valid(u):
    return all(u[i] <= T[i] for i in range(w))

  dist = {S: 0}
  q = [(h(S), S)]
  heapify(q)
  while q:
    dhu, u = heappop(q)
    du = dhu - h(u)
    print(h(u))
    if du > dist[u]:
      continue
    if u == T:
      print(du)
      return du
    for btn in btns:
      v = pressJ(u, btn)
      if not valid(v):
        continue
      dv = du + 1
      if v in dist and dv >= dist[v]:
        continue
      dist[v] = dv
      dvh = dv + h(v)
      heappush(q, (dvh, v))

def partB():
  return sum(aStar(btns, jltg) for _, btns, jltg in INP)

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
