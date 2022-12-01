import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP=lines()

def split():
  out = []
  sm = 0
  for l in INP:
    if not l:
      out.append(sm)
      sm = 0
      continue
    sm += int(l)
  out.append(sm)
  out.sort()
  return out

S = split()

def partA():
  print(S[-1])

def partB():
  print(sum(S[-3:]))

partA()
partB()
