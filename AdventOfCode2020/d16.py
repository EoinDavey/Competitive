import sys
from collections import defaultdict, deque

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()
fields = {}

INF = 10**9

while True:
  l, inp = inp[0], inp[1:]
  if l == "":
    break
  l = l.split(':')
  field = l[0]
  rngs = []
  for rng in l[1].split(' or '):
    l, u = [int(x) for x in rng.split('-')]
    rngs.append((l, u))
  fields[field] = rngs

assert(inp[0] == "your ticket:")
myt, inp = [int(x) for x in inp[1].split(',')], inp[3:]

assert(inp[0] == "nearby tickets:")
inp = inp[1:]
ticks = []
while inp:
  t, inp = [int(x) for x in inp[0].split(',')], inp[1:]
  ticks.append(t)

L = len(myt)
assert(len(fields) == L)
assert(all([len(t) == len(myt) for t in ticks]))

def removeInvalid(ticks):
  sm = 0
  vts = []
  for t in ticks:
    vt = True
    for v in t:
      valid = False
      for f in fields:
        rngs = fields[f]
        for rng in rngs:
          if rng[0] <= v <= rng[1]:
            valid = True
      if not valid:
        vt = False
        sm += v
    if vt:
      vts.append(t)
  return vts, sm

def validIdxs(field, ticks):
  global fields
  rngs = fields[field]
  idxs = []
  for idx in range(L):
    valid = True
    for t in ticks:
      v = t[idx]
      fits = False
      for rng in rngs:
        if rng[0] <= v <= rng[1]:
          fits = True
          break

      if not fits:
        valid = False
        break
    if valid:
      idxs.append(idx)
  return idxs

def partA():
  _, sm = removeInvalid(ticks)
  print(sm)

def partB():
  S = "SOURCE"
  T = "SINK"
  vts, _ = removeInvalid(ticks + [myt])
  res = defaultdict(int)
  vxs = list(fields) + list(range(L)) + [S, T]
  assert(len(set(vxs)) == len(fields) + L + 2)

  for field in fields:
    res[S, field] = 1
  for idx in range(L):
    res[idx, T] = 1
  for field in fields:
    for idx in validIdxs(field, vts):
      res[field, idx] = 1

  dist = defaultdict(lambda: INF)
  p = defaultdict(lambda: -1)
  f = 0

  def aug(u, minE):
    nonlocal f
    if u == S:
      f = minE
      return
    if p[u] != u:
      aug(p[u], min(minE, res[p[u], u]))
      res[p[u], u] -= f
      res[u, p[u]] += f

  mf = 0
  while True:
    f = 0
    for v in vxs:
      dist[v] = INF
      p[v] = v
    dist[S] = 0
    q = deque([S])
    while q:
      u = q.popleft()
      if u == T:
        break
      for v in vxs:
        if res[u, v] > 0 and dist[v] == INF:
          dist[v] = dist[u] + 1
          p[v] = u
          q.append(v)
    aug(T, INF)
    if f == 0:
      break
    mf += f
  assert(mf == L)
  
  ans = 1
  for field in fields:
    if not field.startswith('departure'):
      continue
    for idx in validIdxs(field, vts):
      if res[field, idx] < 1:
        ans *= myt[idx]
  print(ans)


partA()
partB()
