import sys
import re

def lines():
  return [line.strip() for line in sys.stdin]
INP = lines()

def partA():
  sm = 0
  for l in INP:
    dgs = re.findall(r'[0-9]', l)
    sm += int(dgs[0])*10 + int(dgs[-1])
  print(sm)

def partB():
  vals = {
      'one': 1,
      'two': 2,
      'three': 3,
      'four': 4,
      'five': 5,
      'six': 6,
      'seven': 7,
      'eight': 8,
      'nine': 9,
  }
  vals.update((str(x),x) for x in range(10))
  sm = 0
  for l in INP:
    dgs = []
    for i in range(len(l)):
      for (k,v) in vals.items():
        if l[i:i+len(k)] == k:
          dgs.append(v)
          break
    sm += dgs[0]*10 + dgs[-1]
  print(sm)

partA()
partB()
