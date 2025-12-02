import sys

inp = [[int(y) for y in x.split('-')] for x in input().split(',')]

def partA():
  sm = 0
  for l, r in inp:
    for x in range(l, r + 1):
      s = str(x)
      if len(s) % 2 != 0:
        continue
      head, tail = s[:len(s)//2], s[len(s)//2:]
      if head == tail:
        sm += x
  return sm

def partB():
  sm = 0
  for l, r in inp:
    for x in range(l, r + 1):
      s = str(x)
      found = False
      for p in range(2, len(s) + 1):
        if len(s) % p != 0:
          continue
        sz = len(s) // p
        chunks = [s[i:i+sz] for i in range(0, len(s), sz)]
        if all(piece == chunks[0] for piece in chunks):
          found = True
          break
      if found:
        sm += x
  return sm

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
