import sys
from collections import defaultdict

def lines():
  return [line.strip().split() for line in sys.stdin]

INP = lines()

class Dir:
  def __init__(self, p):
    self.p = p
    self.dirs = defaultdict(lambda: Dir(self))
    self.files = {}

def parse():
  root = Dir(None)
  curtree = root
  w = 0
  while w < len(INP):
    cmd = INP[w][1]
    if cmd == "cd":
      tgt = INP[w][2]
      if tgt == '/':
        curtree = root
      elif tgt == '..':
        curtree = curtree.p
      else:
        curtree = curtree.dirs[tgt]
      w += 1
      continue

    assert(cmd == 'ls')
    w += 1
    while w < len(INP) and INP[w][0] != '$':
      t, n = INP[w]
      if t == 'dir':
        pass
      else:
        curtree.files[n] = int(t)

      w += 1
  return root

def sizes(root):
  szs = defaultdict(int)
  def rec(tree):
    for v in tree.dirs.values():
      rec(v)
      szs[tree] += szs[v]
    for v in tree.files.values():
      szs[tree] += v
  rec(root)
  return szs

root = parse()
szs = sizes(root)

def partA():
  print(sum(v for v in szs.values() if v <= 100000))

def partB():
  total = 70000000
  need = 30000000
  cur = total-szs[root]
  delta = need-cur
  print(min(v for v in szs.values() if v >= delta))

partA()
partB()
