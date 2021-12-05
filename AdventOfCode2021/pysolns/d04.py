import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()
seq = [int(x) for x in inp[0].split(',')]
brds = [z[1:] for z in zip(*(iter(inp[1:]),) * 6)]
brds = [[[int(x) for x in r.split()] for r in b] for b in brds]

def checkRs(brd, seen):
  for r in brd:
    if all(x in seen for x in r):
      return True
  return False

def checkCs(brd, seen):
  cl = len(brd[0])
  for c in range(cl):
    if all(brd[r][c] in seen for r in range(len(brd))):
      return True
  return False

def calcWin(brd, seen, s):
  sm = sum([x for r in brd for x in r if x not in seen])
  return s * sm

def partA():
  seen = set()
  for s in seq:
    seen.add(s)
    for brd in brds:
      if checkRs(brd, seen) or checkCs(brd, seen):
        print(calcWin(brd, seen, s))
        return

def partB():
  seen = set()
  won = set()
  v = 0
  for s in seq:
    seen.add(s)
    for i, brd in enumerate(brds):
      if i in won:
        continue
      if checkRs(brd, seen) or checkCs(brd, seen):
        won.add(i)
        v = calcWin(brd, seen, s)
  print(v)

partA()
partB()
