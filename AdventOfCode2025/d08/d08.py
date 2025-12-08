import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP = [tuple(int(x) for x in ln.split(',')) for ln in lines()]

def dist(a, b):
  x1, y1, z1 = INP[a]
  x2, y2, z2 = INP[b]
  return (x1 - x2)**2 + (y1 - y2)**2 + (z1 - z2)**2

ES = [(dist(a, b), a, b) for a in range(len(INP)) for b in range(a)]
ES.sort()

class UFDS:
  def __init__(self, sz):
    self.p = [-1]*sz
    self.sz = [1]*sz

  def find(self, x):
    if self.p[x] == -1:
      return x
    self.p[x] = self.find(self.p[x])
    return self.p[x]

  def union(self, a, b):
    pa = self.find(a)
    pb = self.find(b)
    if pa == pb:
      return False
    self.p[pa] = pb
    self.sz[pb] += self.sz[pa]
    return True

def partA():
  ufds = UFDS(len(INP))
  for _, a, b in ES[:1000]:
    ufds.union(a, b)
  szs = [ufds.sz[i] for i in range(len(INP)) if ufds.find(i) == i]
  szs.sort(reverse=True)
  a, b, c = szs[:3]
  return a * b * c

def partB():
  ufds = UFDS(len(INP))
  lst = None
  for _, a, b in ES:
    if ufds.union(a, b):
      lst = (a, b)
  return INP[lst[0]][0] * INP[lst[1]][0]

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
