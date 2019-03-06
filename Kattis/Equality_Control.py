import time
import sys
osort = sorted

class cat:
  def __init__(self,l,r):
    self.l=l
    self.r=r
    self.t = 'cat'

class sort:
  def __init__(self,v):
    self.v=v
    self.t = 'sort'


class shuf:
  def __init__(self, v):
    self.v=v
    self.t = 'shuf'

def alleq(xs):
  for x in xs:
    if x != xs[0]:
      return False
  return True

def parse(s):
  i = 0
  fst = []
  vst = []
  while i < len(s):
    if s[i] >= 'a' and s[i] <= 'z':
      o = ""
      while s[i] >= 'a' and s[i] <= 'z':
        o+=s[i]
        i+=1
      i+=1 #consume (
      fst.append(o)

    elif s[i] == ')':
      i+=1
      c = fst.pop()
      if c=='concat':
        r = vst.pop()
        l = vst.pop()

        vst.append(cat(l,r))
      elif c=='shuffle':
        v = vst.pop()
        if isinstance(v,(list,)) and alleq(v):
          vst.append(v)
        else:
          vst.append(shuf(v))
      elif c=='sorted':
        v = vst.pop()
        vst.append(sort(v))

    elif s[i] == '[':
      o = ""
      while s[i] != ']':
        o+=s[i]
        i+=1
      o+=s[i]
      i+=1
      vst.append(eval(o))

    elif s[i] == ',':
      i+=1

  assert(len(vst)==1)

  return vst[0]

'''
def comp(t):
  if isinstance(t, (list,)):
    return osort(t)
  if type(t).__name__ == 'cat':
    return comp(t.l) + comp(t.r)
  return comp(t.v)
'''

def comp(t):
  cs = time.time()
  st = [t]
  vst = []
  cm = 0
  while len(st):
    v = st[-1]
    if isinstance(v, (list,)):
      vst.append(osort(v))
      st.pop()
    elif v.t == 'cat':
      if v.l != None:
        st.append(v.l)
        st[-2].l = None
      elif v.r != None:
        st.append(v.r)
        st[-2].r = None
      else:
        r = vst.pop()

        tsts = time.time()
        vst[-1]+=r
        tste = time.time()

        cm += tste-tsts

        st.pop()
    else:
      st.pop()
      st.append(v.v)

  assert(len(vst)==1)
  ce = time.time()
  print "comp took", ce-cs
  print "catting took", cm
  return vst[0]

'''
def ev(t):
  if isinstance(t, (list,)):
    return t
  n = type(t).__name__
  if n=='cat':
    return cat(ev(t.l), ev(t.r))
  if n=='shuf':
    return shuf(comp(t.v))
  if n=='sort':
    return osort(comp(t.v))

'''

def ev(v):
  st = [v]
  vst = []
  while len(st):
    t = st[-1]
    if isinstance(t, (list,)):
      vst.append(t)
      st.pop()
      continue
    n = t.t
    if n == 'cat':
      if t.l != None:
        st.append(t.l)
        st[-2].l=None
      elif t.r != None:
        st.append(t.r)
        st[-2].r=None
      else:
        r = vst.pop()
        l = vst.pop()
        vst.append(cat(l, r))
        st.pop()
    if n == 'shuf':
      vst.append(shuf(comp(t.v)))
      st.pop()
    if n == 'sort':
      vst.append(osort(comp(t.v)))
      st.pop()

  assert(len(vst)==1)
  return vst[0]

'''
def gen(t):
  if isinstance(t, (list,)):
    return t
  if type(t).__name__ == 'cat':
    return gen(t.l) + gen(t.r)

  if type(t).__name__ == 'shuf':
    return [-1] + t.v + [-1]
'''

def gen(v):
  st = [v]
  l = []
  while len(st):
    t = st[-1]
    if isinstance(t, (list,)):
      l += t
      st.pop()
    elif t.t=='cat':
      if t.l != None:
        st.append(t.l)
        st[-2].l = None
      elif t.r != None:
        st.pop()
        st.append(t.r)
    elif t.t=='shuf':
      l.append(-1)
      l += osort(t.v)
      l.append(-1)
      st.pop()

  return str(l)

'''
print gen(ev(parse(raw_input())))
print gen(ev(parse(raw_input())))
'''

if __name__ == "__main__":
  s1 = raw_input()
  s2 = raw_input()
  ps = time.time()
  p = parse(s1)
  pe = time.time()
  print "parse took", pe-ps
  es = time.time()
  e = ev(p)
  ee = time.time()
  print "ev took", ee-es
  gs = time.time()
  g = gen(e)
  ge = time.time()
  print "gen took", ge-gs
  if g == gen(ev(parse(s2))):
    print "equal"
  else:
    print "not equal"
