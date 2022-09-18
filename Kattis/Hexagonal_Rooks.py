from collections import defaultdict

board = set()

def ch(c):
  if c <= 'f':
    return 6 + ord(c) - ord('a')
  return 11 - (ord(c) - ord('f'))

def to3dCoord(o):
  (ch, x) = o
  c = ord(ch) - ord('a')
  if ch <= 'f':
    rl = x
    rr = x + 5 - (ord(ch) - ord('a'))
    return (c, rl, rr)
  rr = x
  rl = x + (ord(ch) - ord('f'))
  return (c, rl, rr)

from3d = {}

def raysFrom(s3):
  sc, srl, srr = s3

  rPts = []
  for (c, rl, rr) in board:
    if c == sc and rl == srl and rr == srr:
      continue
    if c == sc or rl == srl or rr == srr:
      rPts.append((c, rl, rr))

  return rPts

for c in 'abcdefghijk':
  for h in range(1, ch(c) + 1):
    board.add(to3dCoord((c, h)))
    from3d[to3dCoord((c, h))] = (c, h)


inp = [(x[0], int(x[1:])) for x in input().split()]

s = to3dCoord(inp[0])
t = to3dCoord(inp[1])

cnt = 0
for r in raysFrom(s):
  if t in raysFrom(r):
    cnt += 1
 
print(cnt)
