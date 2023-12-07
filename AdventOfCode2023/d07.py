import sys
from collections import Counter
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

INP = [(lambda x: (x[0], int(x[1])))(l.split()) for l in lines()]

def handTypePA(card):
  assert(len(card) == 5)
  cnts = tuple(sorted(Counter(card).values(), reverse=True))
  if cnts == (5,):
    return 7
  if cnts == (4,1):
    return 6
  if cnts == (3,2):
    return 5
  if cnts == (3,1,1):
    return 4
  if cnts == (2,2,1):
    return 3
  if cnts == (2,1,1,1):
    return 2
  if cnts == (1,1,1,1,1):
    return 1
  assert(False)

def valToOrdPA(val):
  if '2' <= val <= '9':
    return int(val)
  return 'TJQKA'.index(val) + 10

def toOrdTuplePA(card):
  t = handTypePA(card)
  return (t,) + tuple(valToOrdPA(x) for x in card)

def partA():
  assert(handTypePA('AAAAA') == 7)
  assert(handTypePA('AA8AA') == 6)
  assert(handTypePA('23332') == 5)
  assert(handTypePA('TTT98') == 4)
  assert(handTypePA('23432') == 3)
  assert(handTypePA('A23A4') == 2)
  inpCopy = [(a,b) for (a,b) in INP]
  inpCopy.sort(key=lambda x: toOrdTuplePA(x[0]))
  print(sum((i+1)*inpCopy[i][1] for i in range(len(inpCopy))))

def valToOrdPB(val):
  if val == 'J':
    return 1
  if '2' <= val <= '9':
    return int(val)
  return 'TQKA'.index(val) + 10

def handTypePB(card):
  assert(len(card)==5)
  ocrd = tuple(card)
  jinxs = [i for i in range(5) if card[i] == 'J']
  if len(jinxs) == 0:
    return handTypePA(card)
  mx = 0
  for jst in product(*(len(jinxs)*['J23456789TQKA'])):
    ncrd = list(ocrd)
    for ji in range(len(jinxs)):
      ncrd[jinxs[ji]] = jst[ji]
    ncrd = tuple(ncrd)
    mx = max(mx, handTypePA(ncrd))
  return mx

def toOrdTuplePB(card):
  t = handTypePB(card)
  return (t,) + tuple(valToOrdPB(x) for x in card)

def partB():
  assert(tuple('J23456789TQKA') == tuple(sorted('J23456789TQKA', key=valToOrdPB)))
  handTypePB('AAAAA')
  handTypePB('JAAAJ')
  inpCopy = [(a,b) for (a,b) in INP]
  inpCopy.sort(key=lambda x: toOrdTuplePB(x[0]))
  print(sum((i+1)*inpCopy[i][1] for i in range(len(inpCopy))))

partA()
partB()
