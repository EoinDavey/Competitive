from collections import defaultdict
nms = [int(x) for x in input().split(',')]

def run(lim):
  diffs, ptime = defaultdict(int), {}
  t, p, cp = 0, 0, nms.copy()
  while t < lim:
    say = 0
    if len(cp):
      say, cp = cp[0], cp[1:]
    else:
      say = diffs[p]
    if say in ptime:
      diffs[say] = t - ptime[say]
    ptime[say] = t
    p = say
    t += 1
  return p

def partA():
  print(run(2020))

def partB():
  print(run(30 * 10**6))

partA()
partB()
