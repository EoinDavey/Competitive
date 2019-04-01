import itertools
from fractions import Fraction
F, B = map(int, raw_input().split())
fs = map(int, raw_input().split())
bs = map(int, raw_input().split())

o = []
for a, b in itertools.product(fs,bs):
  f = Fraction(a,b)
  o.append((f,a,b))

o.sort()
for (a,b,c) in o:
  print "(%d,%d)" % (b,c)
