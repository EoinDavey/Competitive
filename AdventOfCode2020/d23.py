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

def solve(ls, moves):
  cur = ls[0]
  mx = max(ls)
  nxts = [0]*(len(ls) + 1)
  for i in range(len(ls)):
    nxts[ls[i]] = ls[(i+1) % len(ls)]
  for _ in range(moves):
    a, b, c = nxts[cur], nxts[nxts[cur]], nxts[nxts[nxts[cur]]]
    pck = [a, b, c]

    nxts[cur] = nxts[c]

    dst = getDest(cur, mx, pck)
    nxts[dst], nxts[c] = a, nxts[dst]
    cur = nxts[cur]
  return nxts

def partA():
  ls = [int(x) for x in inp]
  nxts = solve(ls, 100)
  st = reduce(lambda x, _: x + str(nxts[int(x[-1])]), range(len(ls) - 1), "1")
  print(st[1:])

def partB():
  ls = [int(x) for x in inp]
  ls += list(range(max(ls) + 1, 10**6 + 1))
  nxts = solve(ls, 10 ** 7)
  print(nxts[1] * nxts[nxts[1]])

partA()
partB()
