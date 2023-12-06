import sys
import re
from math import sqrt, ceil, floor
from functools import reduce

EPS = 1e-6

def lines():
  return [line.strip() for line in sys.stdin]

def readInp():
  tmln, disln = lines()
  tms = [int(x) for x in re.findall('[0-9]+', tmln)]
  dists = [int(x) for x in re.findall('[0-9]+', disln)]
  return list(zip(tms,dists))

INP = readInp()

def slv(t,s):
  rad = sqrt(t*t - 4 * s)
  r1 = (t-rad)/2
  r2 = (t+rad)/2
  return floor(r2-EPS) - ceil(r1+EPS) + 1

def partA():
  print(reduce(lambda x,y: x*y, [slv(t,s) for (t,s) in INP], 1))

def partB():
  T = int(''.join(str(x[0]) for x in INP))
  s = int(''.join(str(x[1]) for x in INP))
  print(slv(T,s))

partA()
partB()
