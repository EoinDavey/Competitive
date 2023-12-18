import sys
import re
from collections import deque
from math import floor

def lines():
  return [line.strip() for line in sys.stdin]
INP = [re.match(r'([ULDR]) ([0-9]+) \(#([a-zA-Z0-9]+)\)', l).groups() for l in lines()]
INP = [(x[0], int(x[1]), x[2]) for x in INP]

drs = {
  'U': (-1, 0),
  'D': (1, 0),
  'L': (0, -1),
  'R': (0, 1),
}

def area(pts):
  sm = 0
  lsm = 0
  for i in range(len(pts)-1): 
    sm += (pts[i][1] + pts[i+1][1])*(pts[i][0] - pts[i+1][0])
    lsm += abs(pts[i][1]-pts[i+1][1]) + abs(pts[i][0]-pts[i+1][0])
  return (abs(sm) + lsm)//2 + 1

def partA():
  pts = [(0, 0)]
  cr = (0, 0)
  for (d, l, c) in INP:
    cr = (cr[0] + l*drs[d][0], cr[1] + l*drs[d][1])
    pts.append(cr)
  print(area(pts))

def partB():
  pts = [(0, 0)]
  cr = (0, 0)
  for (_, _, c) in INP:
    l = int(c[:5], base=16)
    d = 'RDLU'[int(c[-1])]
    cr = (cr[0] + l*drs[d][0], cr[1] + l*drs[d][1])
    pts.append(cr)

  print(area(pts))

partA()
partB()
