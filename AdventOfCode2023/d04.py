import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

CRDS = []
for l in lines():
  crd, nms = l.split(': ')
  _, id_s = crd.split()
  cid = int(id_s)
  ns = [[int(x) for x in ls.split()] for ls in nms.split(' | ')]
  CRDS.append((cid, ns))

def partA():
  sm = 0
  for (_, nms) in CRDS:
    ins = set(nms[0]) & set(nms[1])
    if len(ins) > 0:
      sm += 2**(len(ins)-1)
  print(sm)

def partB():
  cnt = {cid: 1 for (cid, _) in CRDS}
  for (cid, nms) in CRDS:
    mtch = len(set(nms[0]) & set(nms[1]))
    for x in range(1, mtch+1):
      cnt[cid + x] += cnt[cid]
  print(sum(cnt.values()))

partA()
partB()
