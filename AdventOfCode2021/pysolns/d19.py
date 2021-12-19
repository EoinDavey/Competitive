import sys
import re
from itertools import product
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

l = lines()
def getScanners():
  scs = []
  i = 0
  while i < len(l):
    scidx = int(re.search(r'[0-9]+', l[i])[0])
    bcns = []
    i += 1
    while i < len(l) and l[i] != "":
      bcns.append(tuple(int(x) for x in l[i].split(',')))
      i += 1
    scs.append((scidx, bcns))
    i += 1
  return scs

def genRots():
  s = set([(1, 2, 3)])
  stop = False
  while not stop:
    stop = True
    l = len(s)
    for x in list(s):
      s1 = (x[1], -x[0], x[2])
      s2 = (x[2], x[1], -x[0])
      s3 = (x[0], x[2], -x[1])
      s |= set([s1, s2, s3])
    if len(s) > l:
      stop = False
  return list(s)

rots = genRots()

def addPts(a, b):
  return (a[0] + b[0], a[1] + b[1], a[2] + b[2])
def subPts(a, b):
  return (a[0] - b[0], a[1] - b[1], a[2] - b[2])

def sgn(x):
  return -1 if x < 0 else 1

def appRot(pt, rot):
  return (sgn(rot[0]) * pt[abs(rot[0]) - 1],
      sgn(rot[1]) * pt[abs(rot[1]) - 1],
      sgn(rot[2]) * pt[abs(rot[2]) - 1])

imem = {}
def invRot(rot):
  if rot in imem:
    return imem[rot]
  for r in rots:
    if appRot(rot, r) == (1, 2, 3):
      imem[rot] = r
      return r

def rotList(pts, rot):
  return [appRot(pt, rot) for pt in pts]

def evalMatch(da, db, ds1, ds2):
  a = (0, 0, 0)
  b = subPts(da, db)
  sa = set(ds1)
  sb = set(addPts(b, d) for d in ds2)
  match = sa & sb
  if len(match) >= 12:
    return b
  return None

def tryMatch(sc1, sc2):
  ds1, ds2 = sc1[1], sc2[1]
  for r in rots:
    ds2Rot = rotList(ds2, r)
    for da, db in product(ds1, ds2Rot):
      bpos = evalMatch(da, db, ds1, ds2Rot)
      if bpos:
        return (bpos, r)

def getBcns():
  scs = getScanners()
  grph = defaultdict(list)
  for i, j in product(range(len(scs)), range(len(scs))):
    if i >= j:
      continue
    mtch = tryMatch(scs[i], scs[j])
    if mtch == None:
      continue
    bp, r = mtch
    invBp = appRot(bp, invRot(r))
    grph[i].append((j, bp, r))
    grph[j].append((i, subPts((0,0,0), invBp), invRot(r)))

  # (scanner index, rot)
  q = [(0, (1, 2, 3))]
  vis = set()
  pos = {0: (0, 0, 0)}
  allBcns = set()
  while q:
    idx, ra = q.pop()
    p = pos[idx]
    vis.add(idx)
    bcns = set(addPts(p,d) for d in rotList(scs[idx][1], ra))
    allBcns |= bcns
    for n, dpos, rb in grph[idx]:
      if n in vis:
        continue
      rpos = appRot(dpos, ra)
      apos = addPts(p, rpos)
      pos[n] = apos
      q.append((n, appRot(rb, ra)))
  return pos, allBcns

def partA(bcns):
  print(len(bcns))

def partB(scs):
  mx = 0
  scs = list(scPos.values())
  for a, b in product(scs, scs):
    mx = max(mx, abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2]))

  print(mx)

scPos, bcns = getBcns()
partA(bcns)
partB(scPos)
