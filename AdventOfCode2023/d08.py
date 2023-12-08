import sys
import re
from math import gcd
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

def readInp():
  ls = lines()
  p = ls[0]
  mp = {}
  for l in ls[2:]:
    k, lft, rgt = re.match(r'([0-9A-Z]+) = \(([0-9A-Z]+), ([0-9A-Z]+)\)', l).groups()
    mp[k] = (lft, rgt)
  return p, mp

PAT, MP = readInp()

def partA():
  k = 'AAA'
  t = 0
  while k != 'ZZZ':
    k = MP[k][PAT[t % len(PAT)] == 'R']
    t += 1
  print(t)

def partB():
  sts = [k for k in MP.keys() if k.endswith('A')]
  Fs = []
  Ls = []
  for s in sts:
    k = s
    F = 0
    t = 0
    seen = set()
    while (k, t % len(PAT)) not in seen:
      seen.add((k,t % len(PAT)))
      if k.endswith('Z'):
        F = t
      k = MP[k][PAT[t % len(PAT)] == 'R']
      t += 1

    L = 0
    sK = k
    sT = t % len(PAT)
    while True:
      k = MP[k][PAT[t % len(PAT)] == 'R']
      t += 1
      L += 1
      if k == sK and t % len(PAT) == sT:
        break

    k = s
    t = 0
    T = 0
    while True:
      k = MP[k][PAT[t % len(PAT)] == 'R']
      t += 1
      T += 1
      if k == sK and t % len(PAT) == sT:
        break

    # There is only one destination on each cycle, if there were more there could
    # be many possible solutions to check.
    assert(sum(1 for x in seen if x[0].endswith('Z')) == 1)
    # The "runup" to the cycle in my input is always extremely short so it doesn't
    # add any additional constraints as it possibly could.
    assert(T < L)
    Fs.append(F)
    Ls.append(L)

  # If this doesn't hold we need to use CRT but it holds for my input so LCM works.
  assert(all(Fs[i] % Ls[i] == 0 for i in range(len(sts))))
  print(reduce(lambda x, y: x*y // gcd(x,y), Fs, 1))

partA()
partB()
