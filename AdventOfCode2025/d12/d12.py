import sys
import re

def lines():
  return [line.strip() for line in sys.stdin]

def parse():
  inp = lines()
  lp = 0
  shps = []
  while lp < len(inp) and re.match(r'^[0-9]+:$', inp[lp]):
    idx = int(inp[lp][:-1])
    lp += 1
    shp = inp[lp:lp+3]
    shps.append(shp)
    lp += 3
    lp += 1

  grids = [(lambda x: (tuple(int(y) for y in x[0][:-1].split('x')), [int(y) for y in x[1:]]))(ln.split(' ')) for ln in inp[lp:]]
  return shps, grids

SHPS, GRDS = parse()

def partA():
  sm = 0
  for (d, reqs) in GRDS:
    sz = d[0] * d[1]
    need = 0
    n_shps = sum(reqs)
    for shp, r in zip(SHPS, reqs):
      shp_sz = sum(x.count('#') for x in shp)
      need += shp_sz * r
    if sz < need or (sz - need) / n_shps < 2:
      continue
    sm += 1
  return sm

print(f'Part A: {partA()}')
