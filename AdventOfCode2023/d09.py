import sys

def lines():
  return [line.strip() for line in sys.stdin]
INP = [[int(x) for x in l.split()] for l in lines()]

def getNext(l):
  d = l.copy()
  nd = []
  while any(x != 0 for x in d):
    nd.append(d[-1])
    d = [d[i+1] - d[i] for i in range(len(d)-1)]
  return sum(nd)

def partA():
  sm = 0
  for l in INP:
    sm += getNext(l)
  print(sm)

def getPrev(l):
  d = l.copy()
  nd = []
  while any(x != 0 for x in d):
    nd.append(d[0])
    d = [d[i+1] - d[i] for i in range(len(d)-1)]
  o = 0
  for d in nd[::-1]:
    o = d - o
  return o

def partB():
  sm = 0
  for l in INP:
    sm += getPrev(l)
  print(sm)

partA()
partB()
