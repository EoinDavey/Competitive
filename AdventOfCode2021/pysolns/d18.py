import sys

def lines():
  return [line.strip() for line in sys.stdin]

ns = [eval(l) for l in lines()]

class Node:
  def __init__(self, p=None):
    self.l = None
    self.r = None
    self.p = p
  def __str__(self):
    return f'[{self.l}, {self.r}]'
  def order(self):
    return self.l.order() + self.r.order()
  def mag(self):
    return 3 * self.l.mag() + 2 * self.r.mag()
  def findExploder(self, dpth):
    if dpth == 4:
      return self
    return self.l.findExploder(dpth+1) or self.r.findExploder(dpth+1)
  def findSplitter(self):
    return self.l.findSplitter() or self.r.findSplitter()

class Leaf:
  def __init__(self, val, p):
    self.val = val
    self.p = p
  def __str__(self):
    return str(self.val)
  def __repr__(self):
    return str(self.val)
  def mag(self):
    return self.val
  def findExploder(self, _):
    return None
  def findSplitter(self):
    if self.val >= 10:
      return self
    return None

  def order(self):
    return [self]

def toTreeIt(ls, p):
  n = Node(p)
  a, b = ls
  if type(a) == int:
    a = Leaf(a, n)
  else:
    a = toTreeIt(a, n)

  if type(b) == int:
    b = Leaf(b, n)
  else:
    b = toTreeIt(b, n)

  n.l = a
  n.r = b
  return n

def toTree(ls):
  return toTreeIt(ls, None)

def order(t):
  o = t.order()
  return dict(enumerate(o))

def explode(t):
  o = order(t)
  invo = {b:a for a,b in o.items()}
  e = t.findExploder(0)
  if e == None:
    return False
  lidx = invo[e.l]
  if lidx > 0:
    o[lidx-1].val += e.l.val
  ridx = invo[e.r]
  if ridx + 1 < len(o):
    o[ridx+1].val += e.r.val
  ep = e.p
  if e == ep.l:
    ep.l = Leaf(0, ep)
  if e == ep.r:
    ep.r = Leaf(0, ep)
  return True

def split(t):
  s = t.findSplitter()
  if s == None:
    return False
  vl = s.val // 2
  vr = s.val - vl
  sp = s.p
  n = Node(sp)
  l = Leaf(vl, n)
  r = Leaf(vr, n)
  n.l = l
  n.r = r
  if s == sp.l:
    sp.l = n
  if s == sp.r:
    sp.r = n
  return True

def reduce(t):
  mut = True
  while mut:
    mut = False
    if explode(t):
      mut = True
      continue
    if split(t):
      mut = True
  return t

def add(l, r):
  n = Node(None)
  n.l = l
  n.r = r
  l.p = n
  r.p = n
  return reduce(n)

def partA():
  ts = [toTree(n) for n in ns]
  s = ts[0]
  for t in ts[1:]:
    s = add(s, t)
  print('Part 1:', s.mag())

def partB():
  mx = 0
  for na in ns:
    for nb in ns:
      if na == nb:
        continue
      mx = max(mx, add(toTree(na), toTree(nb)).mag())
      mx = max(mx, add(toTree(nb), toTree(na)).mag())
  print(mx)

partA()
partB()
