import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = [(x[0], int(x[1:])) for x in lines()]

def partA():
  pos = 50
  count = 0
  for (d, x) in inp:
    delta = -x if d == 'L' else x
    pos = (pos + delta) % 100
    if pos == 0:
      count += 1
  return count

def partB():
  pos = 50
  count = 0
  for (d, x) in inp:
    delta = -x if d == 'L' else x
    count += x // 100
    npos = (pos + delta) % 100
    if (pos != 0
        and (npos == 0
          or d == 'L' and npos > pos
          or d == 'R' and npos < pos)):
      count += 1
    pos = npos
  return count

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
