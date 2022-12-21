import sys
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]
INP = [int(x) for x in lines()]

class Node:
  def __init__(self, val, l, r):
    self.val = val
    self.l = l
    self.r = r

def swap(B, C):
  A, D = B.l, C.r
  A.r = C
  B.l, B.r = C, D
  C.l, C.r = A, B
  D.l = B

def solve(runs, vals):
  H = Node(vals[0], None, None)
  ref_ls = [H]
  for i in range(1, len(INP)):
    n = Node(vals[i], ref_ls[i-1], None)
    ref_ls[i-1].r = n
    ref_ls.append(n)
  ref_ls[-1].r = ref_ls[0]
  ref_ls[0].l = ref_ls[-1]

  for _ in range(runs):
    for i in range(len(vals)):
      x = abs(vals[i]) % (len(vals) - 1)
      for _ in range(x):
        if vals[i] > 0:
          swap(ref_ls[i], ref_ls[i].r)
        else:
          swap(ref_ls[i].l, ref_ls[i])
  w = H
  while w.val != 0:
    w = w.r
  sm = 0
  for _ in range(3):
    for __ in range(1000 % len(vals)):
      w = w.r
    sm += w.val
  return sm

def partA():
  print(solve(1, INP))

def partB():
  K = 811589153
  vals = [x * K for x in INP]
  print(solve(10, vals))


partA()
partB()
