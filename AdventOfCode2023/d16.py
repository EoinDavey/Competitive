import sys
from itertools import product, chain

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()
H = len(INP)
W = len(INP[0])
valid = lambda x, y: 0 <= x < H and 0 <= y < W
up, dwn, lft, rgt = (-1, 0), (1, 0), (0, -1), (0, 1)
ornt = {
  '\\': {
    up: lft,
    dwn: rgt,
    lft: up,
    rgt: dwn
  },
  '/': {
    up: rgt,
    dwn: lft,
    lft: dwn,
    rgt: up
  }
}

def nbrs(u, d):
  cr = INP[u[0]][u[1]]
  if (cr == '.'
      or (cr == '-' and d in [lft, rgt])
      or (cr == '|' and d in [up, dwn])):
    v = (u[0] + d[0], u[1] + d[1])
    return [(v, d)] if valid(*v) else []

  if cr in '\\/':
    nd = ornt[cr][d]
    v = (u[0] + nd[0], u[1] + nd[1])
    return [(v, nd)] if valid(*v) else []

  assert((cr == '-' and d in [up, dwn])
    or (cr == '|' and d in [lft, rgt]))
  ds = [lft, rgt] if d in [up, dwn] else [up, dwn]
  o = []
  for nd in ds:
    v = (u[0] + nd[0], u[1] + nd[1])
    if valid(*v):
      o.append((v, nd))
  return o

def slv(s, d):
  st = [(s, d)]
  vis = set()
  vis.add((s,d))
  while st:
    u, d = st.pop()
    for n in nbrs(u, d):
      if n in vis:
        continue
      vis.add(n)
      st.append(n)
  return len(set(u for (u, d) in vis))

def partA():
  print(slv((0,0), rgt))

def partB():
  mx = max(slv((x, y), d) for (x, y, d) in chain(
    product([0], range(W), [dwn]),
    product([H-1], range(W), [up]),
    product(range(H), [0], [rgt]),
    product(range(H), [W-1], [lft])))
  print(mx)

partA()
partB()
