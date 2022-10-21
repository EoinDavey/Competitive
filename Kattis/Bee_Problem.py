from collections import defaultdict

h, n, m = [int(x) for x in input().split()]

board = []
adjList = defaultdict(list)

def toInt(u):
  i, j = u
  return i * m + j

def fromInt(x):
  return x // m, x % m

def join(a, b):
  adjList[a].append(b)
  adjList[b].append(a)

for i in range(n):
  l = input().split()
  board.append(l)
  for j in range(len(l)):
    ij = toInt((i, j))
    assert(fromInt(ij) == (i, j))

    if j + 1 < m:
      join((i, j), (i, j+1))

    if i == 0:
      continue
    join((i, j), (i-1, j))
    if i % 2 == 0 and j > 0:
      join((i, j), (i-1, j - 1))
    elif i % 2 == 1 and j + 1 < m:
      join((i, j), (i-1, j + 1))

p = [x for x in range(n * m)]
def find(a):
  pa = p[a]
  if pa == a:
    return a
  npa = find(pa)
  p[a] = npa
  return npa

def join(a, b):
  pa = find(a)
  pb = find(b)
  if pa != pb:
    p[pb] = pa

for i in range(n):
  for j in range(m):
    if board[i][j] == '#':
      continue
    u = (i, j)
    for (vi, vj) in adjList[u]:
      if board[vi][vj] == '#':
        continue
      join(toInt(u), toInt((vi, vj)))

comps = defaultdict(int)
for i in range(n):
  for j in range(m):
    if board[i][j] == '#':
      continue
    comps[find(toInt((i, j)))] += 1

szs = sorted(comps.values())[::-1]

cnt = 0
for x in szs:
  if h <= 0:
    break
  h -= x
  cnt += 1
print(cnt)
