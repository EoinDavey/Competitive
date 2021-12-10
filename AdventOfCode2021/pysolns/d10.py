import sys
from collections import defaultdict

ops = { ')': '(', ']': '[', '}': '{', '>': '<' }

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()

def corrupt(l):
  smp = { ')': 3, ']': 57, '}': 1197, '>': 25137 }
  stck = []
  for x in l:
    if x in "([{<":
      stck.append(x)
      continue
    op = ops[x]
    if len(stck) == 0 or stck[-1] != op:
      return smp[x]
    stck.pop()
  return 0

def partA():
  print(sum(corrupt(l) for l in inp))

def partB():
  nc = [l for l in inp if not corrupt(l)]
  smp = { '(': 1, '[': 2, '{': 3, '<': 4 }
  scrs = []
  for l in nc:
    stck = []
    for x in l:
      if x in "([{<":
        stck.append(x)
      else:
        stck.pop()
    scr = 0
    while len(stck):
      scr = 5 * scr + smp[stck.pop()]
    scrs.append(scr)
  scrs.sort()
  print(scrs[len(scrs) // 2])

partA()
partB()
