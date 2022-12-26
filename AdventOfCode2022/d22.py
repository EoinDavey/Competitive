import sys
import re
from itertools import product, permutations, chain
from collections import namedtuple, defaultdict
from math import sqrt

def lines():
  return [line.rstrip() for line in sys.stdin]
INP = lines()
ww = re.findall(r'[0-9]+|L|R', INP[-1])

INF = 10**6
X = lambda x: int(x.real)
Y = lambda x: int(x.imag)
XY = lambda z: (X(z), Y(z))
trn = lambda z, d: z * [-1j, 1j][d == 'R']

GRD = defaultdict(lambda: ' ', {
  (j, i): l[j] for i, l in enumerate(INP[:-2]) for j in range(len(l))
})

BLCK_SZ = sum(1 for k in GRD.keys() if GRD[k] != ' ')
BLCK_SZ = int(sqrt(BLCK_SZ // 6))

FRONT = [(1, -1, 1), (1, 1, 1), (1, 1, -1), (1, -1, -1)]
face = namedtuple('Face', ['id', 'crnrs'])

def rot_pt_dwn(pt):
  return (pt[2], pt[1], -pt[0])

def rot_pt_up(pt):
  return rot_pt_dwn(rot_pt_dwn(rot_pt_dwn(pt)))

def rot_pt_rgt(pt):
  return (-pt[1], pt[0], pt[2])

def rot_pt_lft(pt):
  return rot_pt_rgt(rot_pt_rgt(rot_pt_rgt(pt)))

def app_rot(r):
  def l(cb):
    for i in range(len(cb)):
      cb[i] = face(cb[i].id, [r(pt) for pt in cb[i].crnrs])
  return l

rot_dwn = app_rot(rot_pt_dwn)
rot_up = app_rot(rot_pt_up)
rot_lft = app_rot(rot_pt_lft)
rot_rgt = app_rot(rot_pt_rgt)

def block_ids():
  assert((len(INP) - 2) % BLCK_SZ == 0)
  blcks_y = (len(INP) - 2) // BLCK_SZ
  xsz = max(len(l) for l in INP[:-2])
  assert(xsz % BLCK_SZ == 0)
  blcks_x = xsz // BLCK_SZ
  blck_id = {}
  b = 0
  bid_to_pos = {}
  for (iy, ix) in product(range(blcks_y), range(blcks_x)):
    if GRD[ix * BLCK_SZ, iy * BLCK_SZ] == ' ':
      continue
    b += 1
    bid_to_pos[b] = (ix * BLCK_SZ, iy * BLCK_SZ)
    for x, y in product(range(BLCK_SZ), range(BLCK_SZ)):
      blck_id[ix * BLCK_SZ + x, iy * BLCK_SZ + y] = b
  return blck_id, bid_to_pos

def build_grph(bids):
  grph = defaultdict(dict)
  for (x, y), v in GRD.items():
    if v == ' ':
      continue
    for d in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
      p = (x + d[0], y + d[1])
      if p not in GRD or GRD[p] == ' ' or bids[x, y] == bids[p]:
        continue
      grph[bids[x,y]][d] = bids[p]
  return grph

def f(u, grph, fcs, vis):
  if u in vis:
    return

  vis.add(u)
  fcs.append(face(u, FRONT))

  for (d, bid) in grph[u].items():
    a, b = {
      (0, 1): (rot_up, rot_dwn),
      (0, -1): (rot_dwn, rot_up),
      (1, 0): (rot_lft, rot_rgt),
      (-1, 0): (rot_rgt, rot_lft),
    }[d]

    a(fcs)
    f(bid, grph, fcs, vis)
    b(fcs)

def find_edge(fc, pts):
  for i in range(4):
    if len(set([fc.crnrs[i], fc.crnrs[(i+1)%4]]) & set(pts)) == 2:
      return i

def edge_seq(fc, s, bid_to_pos):
  e = find_edge(fc, s)
  rv = fc.crnrs[e] != s[0]
  pos = bid_to_pos[fc.id]
  st, d = {
    0: (pos, (1, 0)),
    1: ((pos[0] + BLCK_SZ - 1, pos[1]), (0, 1)),
    2: ((pos[0] + BLCK_SZ - 1, pos[1] + BLCK_SZ - 1), (-1, 0)),
    3: ((pos[0], pos[1] + BLCK_SZ - 1), (0, -1))
  }[e]

  ln = [(st[0] + i * d[0], st[1] + i * d[1]) for i in range(BLCK_SZ)]

  if rv:
    ln.reverse()
  return ln

def union_ax(fa, fb, lp, bid_to_pos):
  s = list(sorted(set(fa.crnrs) & set(fb.crnrs)))
  if len(s) != 2:
    return

  ea = find_edge(fa, s)
  eb = find_edge(fb, s)

  dr = {
    0: (0, -1),
    1: (1, 0),
    2: (0, 1),
    3: (-1, 0)
  }
  op = lambda x: (-dr[x][0], -dr[x][1])

  da, db = dr[ea], dr[eb]
  oa, ob = op(ea), op(eb)

  esa = edge_seq(fa, s, bid_to_pos)
  esb = edge_seq(fb, s, bid_to_pos)

  assert(len(esa) == len(esb))
  for i in range(len(esa)):
    lp[esa[i], da] = (complex(*esb[i]), complex(*ob))
    lp[esb[i], db] = (complex(*esa[i]), complex(*oa))

def mv(ps, d, lp):
  z = ps + d
  if GRD[XY(z)] != ' ':
    return (z, d)
  return lp[XY(ps), XY(d)]

def rn(lp):
  p = INP[0].find('.')
  d = 1
  for w in ww:
    if w in ['L', 'R']:
      d = trn(d, w)
      continue
    for _ in range(int(w)):
      nxt, nd = mv(p, d, lp)
      if GRD[XY(nxt)] == '#':
        break
      p, d = nxt, nd
  d_mp = {(1, 0): 0, (-1, 0): 2, (0, 1): 1, (0, -1): 3}
  return (Y(p)+1) * 1000 + (X(p) + 1) * 4 + d_mp[XY(d)]

def partB():
  bids, bid_to_pos = block_ids()
  grph = build_grph(bids)
  fcs = []
  f(1, grph, fcs, set())

  lp = {}
  for fa, fb in product(fcs, fcs):
    if fa == fb:
      continue
    union_ax(fa, fb, lp, bid_to_pos)
  print(rn(lp))

def partA():
  lp = {}
  rmn = defaultdict(lambda: INF)
  rmx = defaultdict(lambda: -INF)
  cmn = defaultdict(lambda: INF)
  cmx = defaultdict(lambda: -INF)
  for (x, y), v in GRD.items():
    if v == ' ':
      continue
    cmn[x] = min(cmn[x], y)
    cmx[x] = max(cmx[x], y)
    rmn[y] = min(rmn[y], x)
    rmx[y] = max(rmx[y], x)

  assert(all(-INF < x < INF for x in chain(*[x.values() for x in [cmn, cmx, rmn, rmx]])))
  assert(set(cmn.keys()) == set(cmx.keys()))
  assert(set(rmn.keys()) == set(rmx.keys()))
  for c in cmn.keys():
    mn, mx = cmn[c], cmx[c]
    lp[(c, mn), (0, -1)] = (c + mx * (1j), -1j)
    lp[(c, mx), (0, 1)] = (c + mn * (1j), 1j)
  for r in rmn.keys():
    mn, mx = rmn[r], rmx[r]
    lp[(mn, r), (-1, 0)] = (mx + r * (1j), -1)
    lp[(mx, r), (1, 0)] = (mn + r * (1j), 1)

  print(rn(lp))

partA()
partB()
