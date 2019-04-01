import math

T = input()
for _ in xrange(T):
  rg, n = map(int, raw_input().split())
  r = float(rg)
  sm = 0.0
  for i in xrange(n-1):
    r /= 2.0
    sm += pow(3.0, i) * math.pi * r * r
  sm *= 4
  sm += math.pi * rg * rg
  print sm
