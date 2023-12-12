import sys
from functools import lru_cache

def lines():
  return [line.strip() for line in sys.stdin]

def read():
  o = []
  for l in lines():
    pat, xs = l.split()
    xs = tuple(int(x) for x in xs.split(','))
    o.append((pat, xs))
  return o
INP = read()

@lru_cache(maxsize=None)
def fits(i, l, pat):
  if i + l > len(pat):
    return False
  canplace = all(pat[j] in '#?' for j in range(i, i+l))
  placeafter = (i+l == len(pat) or pat[i+l] in '.?')
  return canplace and placeafter

memo = {}
def f(p, i, pat, xs):
  if i >= len(xs):
    return 1 if all(pat[x] in '?.' for x in range(p, len(pat))) else 0
  if p >= len(pat):
    return 0
  if (p, i) in memo:
    return memo[p, i]
  sm = 0
  if fits(p, xs[i], pat):
    sm += f(p + xs[i] + 1, i + 1, pat, xs)
  if pat[p] in '?.':
    sm += f(p + 1, i, pat, xs)
  memo[p, i] = sm
  return sm

def slv(inp):
  sm = 0
  for (pat, xs) in inp:
    memo.clear()
    sm += f(0, 0, pat, xs)
  return sm

def partA():
  print(slv(INP))

def partB():
  print(slv(('?'.join(5*[pat]), xs + xs + xs + xs + xs) for (pat, xs) in INP))

partA()
partB()
