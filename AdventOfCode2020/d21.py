import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

used = {}
allUsed = defaultdict(list)
def tryAll(idx, poss):
  global used, agnl, allUsed
  if idx == len(agnl):
    for k, v in used.items():
      allUsed[k].append(v)
    return
  for opt in poss[agnl[idx]]:
    if opt in used:
      continue
    used[opt] = agnl[idx]
    tryAll(idx + 1, poss)
    del used[opt]

def getPoss():
  poss = {}
  for ing, cont in inp:
    for agn in cont:
      if agn not in poss:
        poss[agn] = set(ing)
      poss[agn] &= set(ing)
  return poss

def partA():
  poss = getPoss()
  ings = set().union(*[set(ing) for ing, _ in inp])

  tryAll(0, poss)
  left = ings - set(list(allUsed))
  cnt = 0
  for ings, _ in inp:
    for ing in ings:
      cnt += ing in left
  print(cnt)

def partB():
  agns = list(allUsed)
  agns.sort(key = lambda x: allUsed[x][0])
  print(','.join(agns))

inp = []
poss = {}
agns = set()
for line in lines():
  ing, cont = line.split(' (')
  ing = ing.split()
  cont = cont[9:-1].split(', ')
  inp.append((ing, cont))
  agns |= set(cont)

agnl = list(agns)

partA()
partB()
