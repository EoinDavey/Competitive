import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

grps = []
grp = []
for line in lines():
    if line == "":
        grps.append(grp)
        grp = []
        continue
    grp.append(line)
grps.append(grp)

def partA():
  sm = 0
  for grp in grps:
    ans = set()
    for p in grp:
      ans |= set(p)
    sm += len(ans)
  print(sm)

def partB():
  sm = 0
  for grp in grps:
    ans = set([chr(x + ord('a')) for x in range(26)])
    for p in grp:
      ans &= set(p)
    sm += len(ans)
  print(sm)

partA()
partB()
