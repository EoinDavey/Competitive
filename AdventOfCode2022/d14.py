import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]
INP=[[tuple(map(int, x.split(','))) for x in l.split('->')] for l in lines()]
GRD = defaultdict(lambda: ' ')

def sgn(x):
  return 0 if x == 0 else x//abs(x)

for l in INP:
  sx, sy = l[0]
  for nx, ny in l[1:]:
    dx, dy = sgn(nx-sx), sgn(ny-sy)
    assert(dx==0 or dy==0)
    GRD[sx, sy] = '#'
    while sx != nx or sy != ny:
      sx += dx
      sy += dy
      GRD[sx, sy] = '#'
    assert(sx==nx or sy==ny)

def sim(grd, cond):
  count = 0
  p = [(500, 0)]
  while True:
    count += 1
    while grd[p[-1]] != ' ':
      p.pop()
    sx, sy = p[-1]
    while True:
      mvd = False
      for (dx, dy) in [(0, 1), (-1, 1), (1, 1)]:
        if grd[sx + dx, sy + dy] == ' ':
          sx += dx
          sy += dy
          mvd = True
          break

      if cond(sx, sy):
        return count

      if not mvd:
        assert(grd[sx, sy] == ' ')
        grd[sx, sy] = 'o'
        break
      p.append((sx, sy))

  print(count-1)

def partA():
  mxy = max(GRD.keys(), key=lambda x: x[1])[1]
  print(sim(GRD.copy(), lambda _, sy: sy > mxy)-1)

def partB():
  grd = GRD.copy()
  mxy = max(grd.keys(), key=lambda x: x[1])[1]
  mxx = max(grd.keys(), key=lambda x: x[0])[0]
  mnx = min(grd.keys(), key=lambda x: x[0])[0]

  cap_y = 2 + mxy
  for x in range(-2*mnx, 2*mxx+1):
    grd[x, cap_y] = '#'

  print(sim(grd, lambda sx, sy: sx == 500 and sy == 0))

partA()
partB()
