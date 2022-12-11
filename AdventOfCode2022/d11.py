import sys
import re
from collections import namedtuple
from functools import reduce

def lines():
  return [line.rstrip() for line in sys.stdin]
INP = [l.strip().split('\n') for l in '\n'.join(lines()).split('\n\n')]

Mnk = namedtuple('Mnk', ['idx', 'its', 'sop', 'd', 'td', 'fd'])

def toFetch(v):
  return (lambda x: x) if v=='old' else (lambda x: int(v))

def toSet(l, op, r):
  l, r = toFetch(l), toFetch(r)
  return (lambda x: l(x) + r(x)) if op == '+' else (lambda x: l(x) * r(x))

def parse():
  mnks = []

  for i, m in enumerate(INP):
    its = [int(x) for x in re.findall(r'[0-9]+', m[1])]
    l, op, r = m[2].split()[3:]
    sop = toSet(l, op, r)
    d = int(m[3].split()[-1])
    td = int(m[4].split()[-1])
    fd = int(m[5].split()[-1])
    assert(td != i and fd != i)

    mnks.append(Mnk(i, its, sop, d, td, fd))
  return mnks

def partA():
  mnks = parse()
  inspCnt = [0]*len(mnks)
  for _ in range(20):
    for i, mnk in enumerate(mnks):
      assert(mnk.idx == i)
      for it in mnk.its:
        inspCnt[i] += 1
        it = mnk.sop(it)
        it //= 3
        if it % mnk.d == 0:
          mnks[mnk.td].its.append(it)
        else:
          mnks[mnk.fd].its.append(it)
      mnk.its.clear()
  inspCnt.sort()
  print(inspCnt[-1] * inspCnt[-2])

def partB():
  mnks = parse()
  D = reduce(lambda a,b: a*b, (m.d for m in mnks), 1)
  inspCnt = [0]*len(mnks)
  for _ in range(10000):
    for i, mnk in enumerate(mnks):
      assert(mnk.idx == i)
      for it in mnk.its:
        inspCnt[i] += 1
        it = mnk.sop(it) % D

        if it % mnk.d == 0:
          mnks[mnk.td].its.append(it)
        else:
          mnks[mnk.fd].its.append(it)

      mnk.its.clear()
  inspCnt.sort()
  print(inspCnt[-1] * inspCnt[-2])

partA()
partB()
