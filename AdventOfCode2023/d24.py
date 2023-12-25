import sys
import random
from itertools import product, chain
from fractions import Fraction

def lines():
  return [line.strip() for line in sys.stdin]
INP = [tuple(tuple(int(x) for x in y.split(', ')) for y in l.split(' @ ')) for l in lines()]

def ldcol(rw):
  nzcs = [i for i in range(len(rw)) if rw[i] != 0]
  return nzcs[0] if len(nzcs) > 0 else -1

def rref(mat):
  cols = len(mat[0])
  rows = len(mat)
  for i in range(cols-1):
    nzrws = [rw for rw in range(rows) if ldcol(mat[rw]) == i]
    if len(nzrws) == 0:
      continue
    nzrw = nzrws[0]
    mat[nzrw] = [x/mat[nzrw][i] for x in mat[nzrw]]
    for rw in range(rows):
      if rw == nzrw or mat[rw][i] == 0:
        continue
      mat[rw] = [mat[rw][j] - mat[rw][i]*mat[nzrw][j] for j in range(cols)]

def slv(a, b):
  (pa, da), (pb, db) = a, b
  mat = [[da[i], -db[i], pb[i]-pa[i]] for i in range(len(pa))]
  rref(mat)
  vs = [[mat[i][-1] for i in range(len(mat)) if mat[i][j] == 1] for j in range(2)]
  if any(len(x) == 0 for x in vs):
    return False
  lm, mu = vs[0][0], vs[1][0]
  if lm < 0 or mu < 0:
    return False
  x, y = pa[0] + da[0]*lm, pa[1] + da[1]*lm
  vld = lambda i: 200000000000000 <= i <= 400000000000000
  return vld(x) and vld(y)

def partA():
  sm = sum(1 for i in range(len(INP)) for j in range(i+1, len(INP)) if slv(INP[i], INP[j]))
  print(sm)

def cross(a, b):
  return [a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]]

def genRows(pi, pj):
  # r + vt = ri + vit
  # iff r - ri = t(vi - v)
  # iff (r-ri) x (vi-v) = 0
  # iff r x vi -(ri x vi) - (r x v) + ri x v = 0
  # 
  # (r x vi) -(ri x vi) -(r x v) + (ri x v) = 0 ∧ (r x vj) -(rj x vj) -(r x v) + (rj x v) = 0
  # => (r x vi) -(ri x vi) + (ri x v) = (r x vj) -(rj x vj) + (rj x v)
  ri, vi = pi
  rj, vj = pj
  rixvi = cross(ri,vi)
  rjxvj = cross(rj,vj)
  m = [
    [0, vi[2]-vj[2], -(vi[1]-vj[1]), 0, -(ri[2]-rj[2]), ri[1]-rj[1], rixvi[0] - rjxvj[0]],
    [-(vi[2]-vj[2]), 0, vi[0]-vj[0], ri[2]-rj[2], 0, -(ri[0]-rj[0]), rixvi[1] - rjxvj[1]],
    [vi[1]-vj[1], -(vi[0]-vj[0]), 0, -(ri[1]-rj[1]), ri[0]-rj[0], 0, rixvi[2] - rjxvj[2]]
  ]
  return [[Fraction(x) for x in y] for y in m]

def partB():
  pidxs = [random.randrange(len(INP)) for _ in range(4)]
  mat = list(chain(*(genRows(INP[i], INP[j]) for (i, j) in product(pidxs, pidxs) if i != j)))
  rref(mat)
  vs = [[mat[i][-1] for i in range(len(mat)) if mat[i][j] == 1] for j in range(6)]
  assert(len(x) > 0 for x in vs)
  x, y, z = [x[0] for x in vs[:3]]
  print(x+y+z)

partA()
partB()
