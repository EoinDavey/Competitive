import sys
from functools import reduce
import re

PAT = re.compile(r'\s*[^\s]+')

def lines():
  return [line for line in sys.stdin]

def parse():
  lns = lines()
  lb = 0
  mxlen = max(len(ln) for ln in lns)
  cols = []
  while lb < mxlen:
    col = [PAT.search(ln, lb)[0] for ln in lns]
    lb += max(len(c) for c in col) + 1
    cols.append(col)
  return cols

COLS = parse()

def partA():
  sm = 0
  for col in COLS:
    f = (lambda x, y: x + y) if col[-1] == '+' else (lambda x, y: x * y)
    sm += reduce(f, [int(x) for x in col[:-1]])
  return sm

def partB():
  sm = 0
  for col in COLS:
    w = max(len(c) for c in col)
    oprnds = [reduce(lambda x, y: 10 * x + y, [int(c[i]) for c in col[:-1] if i < len(c) and c[i] != ' ']) for i in range(w)]
    f = (lambda x, y: x + y) if col[-1] == '+' else (lambda x, y: x * y)
    sm += reduce(f, oprnds)
  return sm

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
