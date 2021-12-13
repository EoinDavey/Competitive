import sys

def lines():
  return [line.strip() for line in sys.stdin]

ls = lines()
dots = []
while ls and ls[0] != "":
  dots.append([int(x) for x in ls[0].split(",")])
  ls = ls[1:]
obrd = {(x,y) for x,y in dots}

folds = [(lambda x: (x[0], int(x[1])))(l.split()[2].split('=')) for l in ls[1:]]

def dofold(brd, v, idx):
  b = set()
  for pt in brd:
    if pt[idx] < v:
      b.add(pt)
      continue
    b.add((2*v - pt[0], pt[1]) if idx == 0 else (pt[0], 2*v - pt[1]))
  return b

def fold(brd, f):
    return dofold(brd, f[1], 0 if f[0] == 'x' else 1)

def partA():
  print(len(fold(obrd, folds[0])))

def partB():
  b = obrd
  for f in folds:
    b = fold(b, f)

  mnx = min(x for x,_ in b)
  mxx = max(x for x,_ in b)
  mny = min(y for _,y in b)
  mxy = max(y for _,y in b)
  for y in range(mny, mxy + 1):
    print(''.join('#' if (x,y) in b else ' ' for x in range(mnx, mxx + 1)))

partA()
partB()
