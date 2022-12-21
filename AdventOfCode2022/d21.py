import sys
from collections import namedtuple

def lines():
  return [line.strip() for line in sys.stdin]

mnk = namedtuple('monkey', ['nm', 'deps', 'ev', 'op'])

def read():
  mnks = {}
  for l in lines():
    n, rhs = l.split(': ')
    rhs = rhs.split()
    if len(rhs) == 1:
      x = int(rhs[0])
      mnks[n] = mnk(n, [], (lambda bnd: (lambda _: bnd))(x), 'lit')
      continue
    a, op, b = rhs
    ev = {
      '+': lambda x, y: x + y,
      '*': lambda x, y: x * y,
      '-': lambda x, y: x - y,
      '/': lambda x, y: x / y,
    }[op]
    mnks[n] = mnk(n, [a, b], (lambda ba, bb, bev: (lambda v: bev(v[ba], v[bb])))(a, b, ev), op)
  return mnks

INP = read()

def solve(mnks):
  q = ['root']
  v = {}
  vis = set()
  while q:
    u = q.pop()
    m = mnks[u]
    if any(d not in vis for d in m.deps):
      q.append(u)
      q += m.deps
      continue
    vis.add(m.nm)
    v[m.nm] = m.ev(v)
  return v['root']

def build_ev(m):
  if m.nm == 'humn':
    return (lambda _: (lambda x: x))

  if m.nm == 'root':
    def f(v):
      a, b = v[m.deps[0]], v[m.deps[1]]
      if callable(a):
        return a(b)
      return b(a)
    return f

  if m.op == 'lit':
    return m.ev

  oev = m.ev
  def g(v):
    a, b = v[m.deps[0]], v[m.deps[1]]
    if (not callable(a)) and (not callable(b)):
      return oev(v)
    if m.op == '+':
      if callable(a):
        return (lambda x: a(x-b))
      return (lambda x: b(x-a))
    if m.op == '-':
      if callable(a):
        return (lambda x: a(x+b))
      return (lambda x: b(a-x))
    if m.op == '*':
      if callable(a):
        return (lambda x: a(x/b))
      return (lambda x: b(x/a))
    assert(m.op == '/')
    if callable(a):
      return (lambda x: a(x*b))
    return (lambda x: b(a/x))
  return g

def partA():
  print(solve(INP))

def partB():
  mnks = {nm: mnk(m.nm, m.deps, build_ev(m), m.op) for nm, m in INP.items()}
  print(solve(mnks))

partA()
partB()
