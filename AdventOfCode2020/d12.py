import sys
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

inp = [(line[0], int(line[1:])) for line in lines()]

# NESW
mvs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
cmdmp = {
    'N': 0, 'E': 1, 'S': 2, 'W': 3,
}

def moveShip(pos, cmd, val):
  x, y, d = pos
  if cmd in 'LR':
    trns = val // 90
    return (x, y, (d + (-trns if cmd == 'L' else trns)) % 4)
  if cmd == 'F':
    return (x + val*mvs[d][0], y + val*mvs[d][1], d)
  idx = cmdmp[cmd]
  return (x + val*mvs[idx][0], y + val*mvs[idx][1], d)

def partA():
  p = reduce(lambda p, d: moveShip(p, d[0], d[1]), inp, (0, 0, 1))
  print(abs(p[0]) + abs(p[1]))

def partB():
  wp = (-1, 10, 0)
  sp = (0, 0)
  for c, v in inp:
    if c in 'NEWS':
      wp = moveShip(wp, c, v)
      continue
    if c == 'F':
      sp = (sp[0] + v * wp[0], sp[1] + v * wp[1])
      continue
    v = v if c == 'L' else 360 - v
    for _ in range(v // 90):
      wp = (-wp[1], wp[0], wp[2])
  print(abs(sp[0]) + abs(sp[1]))

partA()
partB()
