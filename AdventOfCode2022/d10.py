import sys
from collections import defaultdict

def lines():
  return [line.strip().split() for line in sys.stdin]
INP = [l if l[0] == 'noop' else (l[0], int(l[1])) for l in lines()]

def partA():
  t = 1
  reg = 1
  sm = 0
  for l in INP:
    if l[0] == 'noop':
      if (t+20) % 40 == 0:
        sm += t * reg
      t += 1
      continue

    if (t + 21) % 40 <= 1:
      sm += (t+1-((t+1)%20)) * reg

    t += 2
    reg += l[1]
  print(sm)

def partB():
  def f(t,r):
    if (t-1) % 40 in [r-1, r, r+1]:
      print('#', end='')
    else:
      print(' ', end='')
    if (t-1) % 40 == 39:
      print()

  t = 1
  reg = 1
  for l in INP:
    if l[0] == 'noop':
      f(t,reg)
      t += 1
      continue
    f(t,reg)
    f(t+1,reg)

    t += 2
    reg += l[1]

partA()
partB()
