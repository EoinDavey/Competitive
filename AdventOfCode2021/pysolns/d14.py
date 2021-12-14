import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

l = lines()
t = l[0]
prs = [l.split(' -> ') for l in l[2:]]
prs = {(x[0],x[1]): y for x,y in prs}

def union(a,b):
  n = defaultdict(int)
  for k, v in a.items():
    n[k] += v
  for k, v in b.items():
    n[k] += v
  return n

memo = {}
def solvePair(l, r, d):
  if (l,r) not in prs or d == 0:
    return {l: 1, r:1} if l != r else {l: 2}
  if (l,r,d) in memo:
    return memo[l,r,d]
  m = prs[l,r]
  u = union(solvePair(l, m, d - 1), solvePair(m, r, d - 1))
  u[m] -= 1
  memo[l,r,d] = u
  return u

def solveT(t, d):
  sm = defaultdict(int)
  for i in range(len(t) - 1):
    sm = union(sm, solvePair(t[i], t[i+1], d))
    if i > 0:
      sm[t[i]] -= 1
  return max(sm.items(), key=lambda x: x[1])[1] - min(sm.items(), key=lambda x: x[1])[1]

def partA():
  print('Part 1:', solveT(t, 10))

def partB():
  print('Part 2:', solveT(t, 40))

partA()
partB()
