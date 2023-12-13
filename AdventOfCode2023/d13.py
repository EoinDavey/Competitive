import sys

def lines():
  return [line.strip() for line in sys.stdin]
def read():
  o = []
  c = []
  for l in lines():
    if l != "":
      c.append(l)
      continue
    o.append(c)
    c = []
  o.append(c)
  return o
INP = read()

def findSplit(rs, err=0):
  w = len(rs[0])
  for i in range(len(rs)-1):
    p = 0
    e = 0
    while i-p >= 0 and i+1+p < len(rs):
      e += sum(1 for x in range(w) if rs[i-p][x] != rs[i+1+p][x])
      p += 1
    if e == err:
      return i
  return None

def slv(err):
  sm = 0
  for pat in INP:
    if (rsp := findSplit(pat, err)) != None:
      sm += (rsp+1)*100
      continue
    cls = ['.'.join(pat[i][j] for i in range(len(pat))) for j in range(len(pat[0]))]
    sm += findSplit(cls, err) + 1
  return sm

def partA():
  print(slv(0))

def partB():
  print(slv(1))

partA()
partB()
