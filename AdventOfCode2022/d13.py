import sys
from functools import cmp_to_key

def lines():
  return [line.strip() for line in sys.stdin]

INP=lines()
pcks = []
for i in range(0, len(INP), 3):
  pcks.append(eval(INP[i]))
  pcks.append(eval(INP[i+1]))

def comp(l, r):
  if isinstance(l, int) and isinstance(r, int):
    if l < r:
      return 1
    if l > r:
      return -1
    return 0
  
  if isinstance(l, int):
    l = [l]
  if isinstance(r, int):
    r = [r]

  assert(isinstance(l, list) and isinstance(r, list))
  i = 0
  while True:
    if i >= len(l) and i >= len(r):
      assert(len(l) == len(r))
      return 0
    if i >= len(l):
      return 1
    if i >= len(r):
      return -1

    c = comp(l[i], r[i])
    if c != 0:
      return c
    i += 1

def partA():
  sm = 0
  for i in range(0, len(pcks), 2):
    c = comp(pcks[i], pcks[i+1])
    if c == 1:
      sm += i//2 + 1
  print(sm)

def partB():
  p = pcks[:]
  p.append([[2]])
  p.append([[6]])

  p.sort(reverse=True, key=cmp_to_key(comp))
  s = 1
  for i, a in enumerate(p):
    if a == [[2]] or a == [[6]]:
      s *= (i + 1)
  print(s)

partA()
partB()
