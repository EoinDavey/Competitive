import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP = [[[int(x) for x in x.split('-')] for x in l.split(',')] for l in lines()]

def partA():
  cnt = 0
  for (la,ua), (lb, ub) in INP:
    if ((la <= lb and ub <= ua) or
        (lb <= la and ua <= ub)):
      cnt += 1
  print(cnt)

def partB():
  cnt = 0
  for (la,ua), (lb, ub) in INP:
    if max(la, lb) <= min(ua, ub):
      cnt += 1
  print(cnt)

partA()
partB()
