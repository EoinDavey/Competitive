import sys
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

l = lines()
oposs = [int(l.split()[-1]) for l in l]

def partA():
  trn = 0
  rolls = 0
  scrs = [0,0]
  poss = oposs[:]
  die = 0
  while scrs[0] < 1000 and scrs[1] < 1000:
    dv = sum((die + v - 1) % 100 + 1 for v in [1,2,3])
    die = (die + 2) % 100 + 1
    rolls += 3
    poss[trn] = (dv + poss[trn] - 1) % 10 + 1
    scrs[trn] += poss[trn]
    trn = 1 - trn
  print('Part 1:', min(scrs[0]*rolls, scrs[1]*rolls))

def addPair(p1, p2):
  return (p1[0] + p2[0], p1[1] + p2[1])

memo = {}
def simQDie(scrs, poss, trn):
  if scrs[0] >= 21:
    return (1, 0)
  if scrs[1] >= 21:
    return (0, 1)
  if (scrs, poss, trn) in memo:
    return memo[(scrs, poss, trn)]
  res = (0, 0, 0)
  for a, b, c in product((1,2,3), repeat=3):
    sm = a + b + c
    npos = addPair(poss, (sm, 0) if trn == 0 else (0, sm))
    npos = ((npos[0] - 1) % 10 + 1, (npos[1] - 1) % 10 + 1)
    nscrs = addPair(scrs, (npos[0], 0) if trn == 0 else (0, npos[1]))
    res = addPair(res, simQDie(nscrs, npos, 1 - trn))
  memo[(scrs, poss, trn)] = res
  return res

def partB():
  print('Part 2:', max(*simQDie((0, 0), tuple(oposs), 0)))

partA()
partB()
