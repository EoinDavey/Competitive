import sys
import re
from collections import defaultdict
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]
INP=lines()

t_idx = {
  'ore': 0,
  'clay': 1,
  'obsidian': 2,
  'geode': 3,
}

def read():
  bps = []
  for l in INP:
    ss = l.split(': ')[1].split('. ')
    bp = {}
    for s in ss:
      csts = [0]*4
      t = s.split()[1]
      assert(t in t_idx)
      for c in re.findall(r'[0-9]+ [a-z]+', s):
        (cst, sub) = c.split()
        cst = int(cst)
        csts[t_idx[sub]] = cst
      bp[t_idx[t]] = csts
    bps.append(bp)
  return bps

BPS = read()

class Leaf:
  def __init__(self, pt):
    self.pt = pt

  def has_above(self, pt):
    return self.pt != pt and all(self.pt[i] >= pt[i] for i in range(len(pt)))

  def is_leaf(self):
    return True

class KDTree:
  def __init__(self, pts, dpth, D):
    assert(len(pts) > 1)

    mns = [min(pts, key=lambda x: x[i])[i] for i in range(D)]
    mxs = [max(pts, key=lambda x: x[i])[i] for i in range(D)]

    ax = max(range(D), key=lambda x: mxs[x] - mns[x])
    self.ax = ax

    pts.sort(key=lambda x: x[ax])
    md = pts[(len(pts) + 1)//2][ax]
    if md == mns[ax]:
      md += 1
    self.md = md

    l_pts = [pt for pt in pts if pt[ax] < md]
    r_pts = [pt for pt in pts if pt[ax] >= md]
    self.l = make(l_pts, dpth + 1, D)
    self.r = make(r_pts, dpth + 1, D)

  def is_leaf(self):
    return False

def mrk_below(root, pt, blkd):
  st = [root]
  while st:
    u = st.pop()
    if u.is_leaf():
      if u.pt != pt and all(u.pt[i] <= pt[i] for i in range(len(pt))):
        blkd.add(u.pt)
      continue

    if pt[u.ax] < u.md:
      if u.l:
        st.append(u.l)
    else:
      if u.l:
        st.append(u.l)
      if u.r:
        st.append(u.r)

def make(pts, dpth, D):
  if len(pts) == 0:
    return None
  if len(pts) == 1:
    return Leaf(pts[0])
  return KDTree(pts, dpth, D)

def pareto_frnt(ls, t_rem):
  ls = list(set(ls))
  ls.sort(key=lambda x: sum(x))
  mxg = max(l[-1] for l in ls)
  mx_poss = max(0, (t_rem * (t_rem - 1)) // 2)
  ls = [l for l in ls if l[-1] + mx_poss >= mxg]
  T = make(ls, 0, len(ls[0]))
  blckd = set()
  for x in ls:
    if x not in blckd:
      mrk_below(T, x, blckd)
  o = [x for x in ls if x not in blckd]
  return o

def solve(bp, N):
  P = [{}]*(N+1)

  P[0] = {(1, 0, 0):  [(0, 0, 0, 0)]}
  for t in range(1,N+1):
    n_sols = []

    for p_k, p_ls in P[t-1].items():
      assert(len(p_k) == 3)

      for p_opt in p_ls:
        assert(len(p_opt) == 4)

        for (typ, csts) in bp.items():
          if any(csts[i] > p_opt[i] for i in range(3)):
            continue
          res = [p_opt[i] - csts[i] + p_k[i] for i in range(3)] + [p_opt[3]]
          rbts = list(p_k)
          if typ < 3:
            rbts[typ] += 1
          else:
            res[3] += (N-t)

          rbts = tuple(rbts)
          res = tuple(res)

          n_sols.append(rbts + res)

        res = tuple([p_opt[i] + p_k[i] for i in range(3)] + [p_opt[-1]])
        n_sols.append(p_k + res)

    P[t] = defaultdict(list)
    pf = pareto_frnt(n_sols, N - t)
    for n in pf:
      P[t][n[:3]].append(n[3:])

  mx = 0
  for p_k, p_ls in P[-1].items():
    for l in p_ls:
      mx = max(mx, l[-1])
  return mx

def partA():
  sm = 0
  for i, bp in enumerate(BPS):
    sm += (i+1) * solve(bp, 24)
  print(sm)

def partB():
  m = 1
  for i, bp in enumerate(BPS[:3]):
    m *= solve(bp, 32)
  print(m)

partA()
partB()
