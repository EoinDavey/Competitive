import sys
from collections import defaultdict
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]
INP = ''.join(lines())
coms = INP.split(',')

def hash(s):
  return reduce(lambda sm, c: ((sm + ord(c))*17) % 256, s, 0)

def partA():
  print(sum(hash(s) for s in coms))

def rem(boxes, lbl):
  a = boxes[hash(lbl)]
  for i in range(len(a)):
    if a[i][0] == lbl:
      del a[i]
      return

def st(boxes, lbl, v):
  a = boxes[hash(lbl)]
  for i in range(len(a)):
    if a[i][0] == lbl:
      a[i] = (lbl, v)
      return
  a.append((lbl, v))

def partB():
  boxes = defaultdict(list)
  for com in coms:
    if com[-1] == '-':
      rem(boxes, com[:-1])
      continue
    lbl, v = com.split('=')
    st(boxes, lbl, int(v))
  sm = 0
  for (bid, ls) in boxes.items():
    for i, (lbl, v) in enumerate(ls):
      sm += (bid + 1) * (i+1) * v
  print(sm)

partA()
partB()
