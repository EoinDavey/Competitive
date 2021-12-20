import sys
from itertools import product
from collections import defaultdict

mvs = [(1, 1), (1, 0), (1, -1), (0, 1), (0, 0), (0, -1), (-1, 1), (-1, 0), (-1, -1)] 

def lines():
  return [line.strip() for line in sys.stdin]

def ns(pt):
  return [(n[0] + pt[0], n[1] + pt[1]) for n in mvs]

l = lines()
alg = l[0]

ob = [[x for x in l] for l in l[2:]]
ob = {(x, y): ob[x][y] for x, y in product(range(len(ob)), range(len(ob[0])))}

def sim(its):
  b = ob
  rest = '.'
  for _ in range(its):
    pts2up = list(set([n for pt in b.keys() for n in ns(pt)]))
    nb = {}
    for pt in pts2up:
      sm = 0
      for off, n in enumerate(ns(pt)):
        v = b[n] if n in b else rest
        if v == '.':
          continue
        sm += 2**off
      nb[pt] = alg[sm]
    rest = alg[0] if rest == '.' else alg[2**8 - 1]
    b = nb
  return len([k for k,v in b.items() if v == '#'])

def partA():
  print('Part 1:', sim(2))

def partB():
  print('Part 2:', sim(50))

partA()
partB()
