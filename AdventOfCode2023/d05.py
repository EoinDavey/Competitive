import sys
INF=10**10
ORDR = ['soil', 'fertilizer', 'water', 'light', 'temperature', 'humidity', 'location']

def lines():
  return [line.strip() for line in sys.stdin]

def parse():
  inp = lines()
  sds = [int(x) for x in inp[0].split(': ')[1].split()]
  i = 2
  mps = {}
  while i < len(inp):
    title = inp[i].split(' ')
    nm = title[0]
    i += 1
    vs = []
    while i < len(inp):
      if inp[i] == '':
        break
      vs.append([int(x) for x in inp[i].split()])
      i += 1
    i += 1
    mps[nm] = vs
    for v in vs:
      assert(all(x < INF for x in v))
  return (sds, mps)

SDS, MPS = parse()

def mapVal(x, mp):
  for (ds, src, l) in mp:
    if src <= x < src + l:
      return ds + (x-src)
  return x

def partA():
  mn = 10**10
  for s in SDS:
    p = 'seed'
    for o in ORDR:
      mp = MPS[f'{p}-to-{o}']
      s = mapVal(s, mp)
      p = o
    mn = min(mn, s)
  print(mn)

def splitRanges(inrngs, splits):
  inrngs.sort()
  fullsplits = []
  if splits[0][0] != 0:
    fullsplits.append((0, splits[0][0]-1))
  for i in range(len(splits)):
    fullsplits.append(splits[i])
    if i+1 < len(splits) and splits[i+1][0]-1 != splits[i][1]:
      fullsplits.append((splits[i][1]+1, splits[i+1][0]-1))
  fullsplits.append((fullsplits[-1][1]+1, INF))

  outrngs = []
  for (sr, er) in inrngs:
    for (ss, es) in fullsplits:
      sovr = max(sr, ss)
      eovr = min(er, es)
      if sovr <= eovr:
        outrngs.append((sovr,eovr))
  outrngs.sort()

  return outrngs

def mapRanges(inrngs, mp):
  splits = [src for (src, _) in mp]
  inputSplit = splitRanges(inrngs, splits)
  out = []
  for (b, e) in inputSplit:
    fnd = False
    for (src, dest) in mp:
      if max(b, src[0]) <= min(e, src[1]):
        o = (b+(dest[0]-src[0]), e + (dest[0] - src[0]))
        out.append(o)
        fnd = True
    if not fnd:
      out.append((b,e))
  return out

def partB():
  sdrngs = [(SDS[i], SDS[i] + SDS[i+1] - 1) for i in range(0, len(SDS), 2)]
  maps = {}
  for (nm, specs) in MPS.items():
    rngmaps = []
    for (ds, src, l) in specs:
      rngmaps.append(((src, src + l - 1), (ds, ds + l - 1)))
    rngmaps.sort()
    maps[nm] = rngmaps

  s = sdrngs
  p = 'seed'
  for o in ORDR:
    s = mapRanges(s, maps[f'{p}-to-{o}'])
    p = o
  s.sort()
  print(s[0][0])

partA()
partB()
