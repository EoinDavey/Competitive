import sys
import re
from itertools import product

class Cube:
  def __init__(self, x1, x2, y1, y2, z1, z2):
    assert x1 <= x2 and y1 <= y2 and z1 <= z2
    self.x1, self.x2, self.y1, self.y2, self.z1, self.z2 = x1, x2, y1, y2, z1, z2
    self.vs = [x1,x2,y1,y2,z1,z2]

  def axis(self, ax):
    return self.vs[2*ax:2*ax+2]

  def hasInt(self, cb2):
    for axis in [0, 1, 2]:
      vs1, vs2 = self.axis(axis), cb2.axis(axis)
      if vs1[0] > vs2[1] or vs2[0] > vs1[1]:
        return False
    return True

  def contains(self, cb2):
    for axis in [0, 1, 2]:
      me, vs2 = self.axis(axis), cb2.axis(axis)
      if vs2[0] < me[0] or vs2[1] > me[1]:
        return False
    return True

  def volume(self):
    return (self.x2 - self.x1 + 1) * (self.y2 - self.y1 + 1) * (self.z2 - self.z1 + 1)

  def __sub__(self, cb2):
    ints = []
    for axis in [0, 1, 2]:
      allVs = sorted(self.axis(axis) + cb2.axis(axis))
      intsctns = []
      for i, (a, b) in enumerate(zip(allVs, allVs[1:])):
        if i == 0:
          b -= 1
        if i == len(allVs) - 2:
          a += 1
        if b >= a:
          intsctns.append((a, b))
      ints.append(intsctns)

    cbs = [Cube(*[v for ax in cb for v in ax]) for cb in product(*ints)]

    return [cb for cb in cbs if self.contains(cb) and not cb2.contains(cb)]

def lines():
  return [line.strip() for line in sys.stdin]

inp = [(l[:2], Cube(*[int(x) for x in re.findall(r'[-0-9]+', l)])) for l in lines()]

def partA():
  cbs = {}
  for c,cb in inp:
    x1 = max(cb.x1, -50)
    y1 = max(cb.y1, -50)
    z1 = max(cb.z1, -50)
    x2 = min(cb.x2, 50)
    y2 = min(cb.y2, 50)
    z2 = min(cb.z2, 50)
    if x1 > x2 or y1 > y2 or z1 > z2:
      continue
    for x, y, z in product(range(x1, x2+1), range(y1, y2+1), range(z1, z2+1)):
      cbs[x,y,z] = c == 'on'
  cnt = 0
  for (x, y, z), v in cbs.items():
    if v and abs(x) <= 50 and abs(y) <= 50 and abs(z) <= 50:
      cnt += 1
  print('Part 1:', cnt)

def partB():
  cbs = []
  for i, (cm, cub1) in enumerate(inp):
    ncubs = []
    for cb in cbs:
      if not cub1.hasInt(cb):
        ncubs.append(cb)
        continue
      ncubs.extend(cb - cub1)

    if cm == "on":
      ncubs.append(cub1)
    cbs = ncubs

  print('Part 2:', sum(cb.volume() for cb in cbs))

partA()
partB()
