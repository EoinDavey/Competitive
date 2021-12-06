import sys
from collections import defaultdict

start = [int(x) for x in input().split(',')]

def proc(days):
  cnts = defaultdict(int)
  for f in start:
    cnts[f] += 1
  for _ in range(days):
    nc = defaultdict(int)
    for k, v in cnts.items():
      nc[k - 1] = v
    nc[6] += nc[-1]
    nc[8] += nc[-1]
    del nc[-1]
    cnts = nc
  return sum(cnts.values())

def partA():
  print(proc(80))

def partB():
  print(proc(256))

partA()
partB()
