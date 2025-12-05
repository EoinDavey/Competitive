import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP = lines()
gap = INP.index('')
RANGES = [[int(y) for y in x.split('-')] for x in INP[:gap]]
IDS = [int(x) for x in INP[gap + 1:]]

def partA():
  count = 0
  for id in IDS:
    if any(rng[0] <= id <= rng[1] for rng in RANGES):
      count += 1
  return count

def partB():
  pts = []
  for l, r in RANGES:
    pts.append((l, False))
    pts.append((r, True))
  pts.sort()

  tot = 0
  hgt = 0
  lb = -1
  for pos, typ in pts:
    if typ == False:
      hgt += 1
      if lb == -1:
        lb = pos
    else:
      hgt -= 1
      if hgt == 0:
        tot += pos - lb + 1
        lb = -1
  return tot

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
