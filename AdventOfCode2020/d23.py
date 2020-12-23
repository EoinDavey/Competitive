import sys
from functools import reduce

inp = input()

def getDest(cur, mx, pck):
  t = cur
  while True:
    t -= 1
    if t < 1:
      t = mx
    if t not in pck:
      return t

def solve(ls, nxts, moves):
  cur = ls[0]
  mx = max(ls)
  for _ in range(moves):
    a = nxts[cur]
    b = nxts[a]
    c = nxts[b]
    pck = a, b, c

    nxts[cur] = nxts[c]

    dst = getDest(cur, mx, pck)
    nxts[dst], nxts[c] = a, nxts[dst]
    cur = nxts[cur]

def partA():
  nxts = [0]*(len(inp) + 1)
  ls = [int(x) for x in inp]
  for i in range(len(ls)):
    nxts[ls[i]] = ls[(i+1) % len(ls)]
  solve(ls, nxts, 100)
  st = reduce(lambda x, _: x + str(nxts[int(x[-1])]), range(len(ls) - 1), "1")
  print(st[1:])

def partB():
  nxts = [0]*(10**6 + 1)
  ls = [int(x) for x in inp]
  ls += list(range(max(ls) + 1, 10**6 + 1))
  for i in range(len(ls)):
    nxts[ls[i]] = ls[(i+1) % len(ls)]
  solve(ls, nxts, 10 ** 7)
  print(nxts[1] * nxts[nxts[1]])

partA()
partB()
