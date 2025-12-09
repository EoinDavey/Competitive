import sys
from itertools import product

def lines():
  return [line.strip() for line in sys.stdin]

REDS = [tuple(int(x) for x in ln.split(',')) for ln in lines()]

def sz(i, j):
  xi, yi = REDS[i]
  xj, yj = REDS[j]
  return (abs(xi - xj) + 1) * (abs(yi - yj) + 1)

def partA():
  return max(sz(i, j) for i in range(len(REDS)) for j in range(i))

def compress(pts):
  uniques = set(pts)
  ls = list(sorted(uniques))
  pt_map = {ls[0]: 1}
  for i in range(1, len(ls)):
    pt = ls[i]
    ppt = ls[i - 1]
    p_val = pt_map[ppt]
    if pt == ppt + 1:
      pt_map[pt] = p_val + 1
    else:
      pt_map[pt] = p_val + 2
  return pt_map

def partB():
  x_map = compress(REDS[i][0] for i in range(len(REDS)))
  y_map = compress(REDS[i][1] for i in range(len(REDS)))
  x_comp_max = max(x_map.values()) + 1
  y_comp_max = max(y_map.values()) + 1
  comp_grid = [['.']*(y_comp_max + 1) for _ in range(x_comp_max + 1)]
  for x, y in REDS:
    x_comp = x_map[x]
    y_comp = y_map[y]
    comp_grid[x_comp][y_comp] = '#'

  for i in range(len(REDS)):
    x, y = REDS[i]
    x_comp, y_comp = x_map[x], y_map[y]
    px, py = REDS[(i - 1) % len(REDS)]
    px_comp, py_comp = x_map[px], y_map[py]
    sign = lambda x: 1 if x > 0 else (0 if x == 0 else -1)
    dx, dy = sign(x_comp - px_comp), sign(y_comp - py_comp)

    wx, wy = px_comp + dx, py_comp + dy
    while (wx, wy) != (x_comp, y_comp):
      comp_grid[wx][wy] = 'X'
      wx += dx
      wy += dy

  sx = [x for x in range(x_comp_max + 1) if comp_grid[x][0] == '.'][0]
  q = [(sx, 0)]
  seen = set(q)
  while q:
    ux, uy = q.pop()
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
      vx, vy = ux + dx, uy + dy
      if (vx, vy) in seen or not (0 <= vx <= x_comp_max and 0 <= vy <= y_comp_max):
        continue
      if comp_grid[vx][vy] != '.':
        continue
      seen.add((vx, vy))
      q.append((vx, vy))

  for x in range(x_comp_max + 1):
    for y in range(y_comp_max + 1):
      if comp_grid[x][y] == '.' and (x, y) not in seen:
        comp_grid[x][y] = ' '

  pref_sum = [[0]*len(comp_grid[0]) for _ in range(len(comp_grid))]
  for i in range(len(pref_sum)):
    for j in range(len(pref_sum[0])):
      if comp_grid[i][j] == '.':
        pref_sum[i][j] = 1
      if i > 0:
        pref_sum[i][j] += pref_sum[i - 1][j]
      if j > 0:
        pref_sum[i][j] += pref_sum[i][j - 1]

      if i > 0 and j > 0:
        pref_sum[i][j] -= pref_sum[i - 1][j - 1]

  mx = 0
  for i in range(len(REDS)):
    xi, yi = REDS[i]
    xi_comp, yi_comp = x_map[xi], y_map[yi]
    for j in range(i):
      xj, yj = REDS[j]
      xj_comp, yj_comp = x_map[xj], y_map[yj]
      x_min, x_max = min(xi_comp, xj_comp), max(xi_comp, xj_comp)
      y_min, y_max = min(yi_comp, yj_comp), max(yi_comp, yj_comp)
      count = pref_sum[x_max][y_max]
      if x_min > 0:
        count -= pref_sum[x_min - 1][y_max]
      if y_min > 0:
        count -= pref_sum[x_max][y_min - 1]
      if x_min > 0 and y_min > 0:
        count += pref_sum[x_min - 1][y_min - 1]

      if count == 0:
        mx = max(mx, sz(i, j))
  return mx

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
