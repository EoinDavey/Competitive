import sys
from collections import deque

rcks = [
    [(0, 0), (1, 0), (2, 0), (3, 0)],
    [(0, -1), (1, -1), (2, -1), (1, 0), (1, -2)],
    [(0, 0), (1, 0), (2, 0), (2, -1), (2, -2)],
    [(0, 0), (0, -1), (0, -2), (0, -3)],
    [(0, 0), (0, -1), (1, 0), (1, -1)],
]

INP=input()

def rn(R, col=set(), mv_idx=0, r=0, top=0):
  for _ in range(R):
    while any((x, top) in col for x in range(7)):
      top -= 1
    sp_y = top - 3
    sp_x = 2

    pos = [(sp_x + dx, sp_y + dy) for (dx, dy) in rcks[r]]

    while True:
      dx = -1 if INP[mv_idx] == '<' else 1
      mv_idx = (mv_idx + 1) % len(INP)
      if any(x + dx < 0 or x + dx >= 7 or (x + dx, y) in col for (x, y) in pos):
        pass
      else:
        pos = [(x+dx, y) for (x, y) in pos]

      if any(y + 1 > 0 or (x, y + 1) in col for (x, y) in pos):
        col |= set(pos)
        break

      pos = [(x, y + 1) for (x, y) in pos]

    r = (r + 1) % 5
  while any((x, top) in col for x in range(7)):
    top -= 1
  return (-top, mv_idx)

def partA():
  print(rn(2022)[0])

def partB():
  T = 1000000000000
  col = set()
  top = 0
  r = 0
  mv_idx = 0

  memo = {}

  t = 0
  while True:
    q = deque([(0, top)])
    vis = set([(0, top)])
    while q:
      (ux, uy) = q.popleft()
      for (dx, dy) in [(1, 0), (-1, 0), (0, 1)]:
        nx, ny = ux + dx, uy + dy
        if nx < 0 or nx >= 7 or ny > 0 or (nx, ny) in vis or (nx, ny) in col:
          continue
        vis.add((nx, ny))
        q.append((nx, ny))
    if len(vis) < 20:
      k = (tuple(sorted([(x, y-top) for (x, y) in vis])), mv_idx)
      if k in memo:
        (pv_top, pv_t) = memo[k]
        rcks_p = t - pv_t
        rem_rcks = T - t
        rem_rcks_p = rem_rcks % rcks_p
        pds = rem_rcks // rcks_p
        LH = (-top) + ((-top) - pv_top) * pds

        ans = LH + rn(rem_rcks_p, col, mv_idx, r, top)[0] - (-top)

        print(ans)
        return
      memo[k] = (-top, t)

    (top, mv_idx) = rn(1, col, mv_idx, r, top)
    top = -top

    r = (r + 1) % 5
    t += 1

partA()
partB()
