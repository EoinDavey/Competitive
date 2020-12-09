import sys
from collections import deque

def lines():
  return [line.strip() for line in sys.stdin]

inp = [int(x) for x in lines()]

def keynum():
  q = deque(inp[:25])
  for x in inp[25:]:
    s = set()
    valid = False
    for u in q:
      if x - u in s:
        valid = True
      s.add(u)
    if not valid:
      return x
    q.popleft()
    q.append(x)

k = keynum()

def partA():
  print(k)

def partB():
  psum = [inp[0]]
  for x in inp[1:]:
    psum.append(x + psum[-1])
  for r in range(len(inp)):
    for l in range(r):
      sm = psum[r] - (0 if l == 0 else psum[l-1])
      if sm != k:
        continue
      print(min(inp[l:r+1]) + max(inp[l:r+1]))
      return

partA()
partB()
