import sys
import re
from functools import reduce, lru_cache

def lines():
  return [line.strip() for line in sys.stdin]

def parsewf(wf):
  name, desc, last = re.match(r'([a-z]+){(.*),([a-zA-Z]+)}', wf).groups()
  stpsdsc = re.findall(r'([xmas])([><])([0-9]+):([a-zA-Z]+),?', desc)
  stpsdsc = [(a,b,int(c),d) for (a,b,c,d) in stpsdsc]
  return (name, (stpsdsc, last))

def parse():
  ls = lines()
  gp = ls.index('')
  wfls = ls[:gp]
  xls = ls[gp+1:]

  wfs = [parsewf(wf) for wf in wfls]
  xs = [re.match(r'{x=([0-9]+),m=([0-9]+),a=([0-9]+),s=([0-9]+)}', l).groups() for l in xls]
  xs = [(int(x), int(m), int(a), int(s)) for (x, m, a, s) in xs]
  return dict(wfs), xs

WFS, XS = parse()

def ev(c, s, v, xmas):
  cmp = (lambda x: x > v) if s == '>' else (lambda x: x < v)
  return cmp(xmas['xmas'.index(c)])

def runWFs(xmas):
  wf = 'in'
  while wf not in 'AR':
    stps, last = WFS[wf]
    fnd = False
    for (c, s, v, d) in stps:
      if ev(c, s, v, xmas):
        wf = d
        fnd = True
        break
    if not fnd:
      wf = last
  return wf == 'A'

def partA():
  print(sum(sum(xs) for xs in XS if runWFs(xs)))

def clip(xmasr, c, s, v):
  i = 'xmas'.index(c)
  rng = xmasr[i]
  rngt, rngf = ((1, v-1), (v, 4000)) if s == '<' else ((v+1, 4000), (1, v))

  nrngt = (max(rng[0], rngt[0]), min(rng[1], rngt[1]))
  nrngf = (max(rng[0], rngf[0]), min(rng[1], rngf[1]))
  if nrngt[0] > nrngt[1]:
    nrngt = None
  if nrngf[0] > nrngf[1]:
    nrngf = None
  o = list(xmasr)
  o[i] = nrngt
  t = tuple(o)
  o[i] = nrngf
  f = tuple(o)
  return t, f

@lru_cache(maxsize=None)
def combs(wf, xmasr):
  if wf == 'R':
    return 0
  if wf == 'A':
    return reduce(lambda x, y: x * (y[1]-y[0]+1), xmasr, 1)
  sm = 0
  stps, last = WFS[wf]
  wlk = xmasr
  for (c, s, v, d) in stps:
    rngt, rngf = clip(wlk, c, s, v)
    if rngt != None:
      sm += combs(d, rngt)
    wlk = rngf
    if rngf == None:
      break
  if wlk != None:
    sm += combs(last, wlk)
  return sm

def partB():
  print(combs('in', tuple(4*[(1, 4000)])))

partA()
partB()
