import sys
from collections import Counter
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

INP = [(lambda x: (x[0], int(x[1])))(l.split()) for l in lines()]

def handType(card):
  cnts = tuple(sorted(Counter(card).values(), reverse=True))
  return {
    (5,): 7, (4,1): 6, (3,2): 5, (3,1,1): 4, (2,2,1): 3, (2,1,1,1): 2, (1,1,1,1,1): 1,
    (4,): 7, (3,1): 6, (2,2): 5, (2,1,1): 4, (1,1,1,1): 2,
    (3,): 7, (2,1): 6, (1,1,1): 4,
    (2,): 7, (1,1): 6,
    (1,): 7,
    (): 7,
  }[cnts]

def valToOrdPA(val):
  if '2' <= val <= '9':
    return int(val)
  return 'TJQKA'.index(val) + 10

def toOrdTuplePA(card):
  return (handType(card),) + tuple(valToOrdPA(x) for x in card)

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

def toOrdTuplePB(card):
  return (handType(c for c in card if c != 'J'),) + tuple(valToOrdPB(x) for x in card)

def partB():
  inpCopy = INP.copy()
  inpCopy.sort(key=lambda x: toOrdTuplePB(x[0]))
  print(sum((i+1)*inpCopy[i][1] for i in range(len(inpCopy))))

partA()
partB()
