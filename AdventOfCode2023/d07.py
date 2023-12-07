import sys
from collections import Counter
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

INP = [(lambda x: (x[0], int(x[1])))(l.split()) for l in lines()]

def handTypePA(card):
  cnts = tuple(sorted(Counter(card).values(), reverse=True))
  return {
    (5,): 7,
    (4,1): 6,
    (3,2): 5,
    (3,1,1): 4,
    (2,2,1): 3,
    (2,1,1,1): 2,
    (1,1,1,1,1): 1
  }[cnts]

def valToOrdPA(val):
  if '2' <= val <= '9':
    return int(val)
  return 'TJQKA'.index(val) + 10

def toOrdTuplePA(card):
  return (handTypePA(card),) + tuple(valToOrdPA(x) for x in card)

def partA():
  inpCopy = INP.copy()
  inpCopy.sort(key=lambda x: toOrdTuplePA(x[0]))
  print(sum((i+1)*inpCopy[i][1] for i in range(len(inpCopy))))

def valToOrdPB(val):
  if val == 'J':
    return 1
  if '2' <= val <= '9':
    return int(val)
  return 'TQKA'.index(val) + 10

def handTypePB(card):
  ocrd = tuple(card)
  jinxs = [i for i in range(5) if card[i] == 'J']
  if len(jinxs) == 0:
    return handTypePA(card)
  mx = 0
  for jst in product(*(len(jinxs)*['J23456789TQKA'])):
    ncrd = list(ocrd)
    for ji in range(len(jinxs)):
      ncrd[jinxs[ji]] = jst[ji]
    mx = max(mx, handTypePA(ncrd))
  return mx

def toOrdTuplePB(card):
  return (handTypePB(card),) + tuple(valToOrdPB(x) for x in card)

def partB():
  inpCopy = INP.copy()
  inpCopy.sort(key=lambda x: toOrdTuplePB(x[0]))
  print(sum((i+1)*inpCopy[i][1] for i in range(len(inpCopy))))

partA()
partB()
