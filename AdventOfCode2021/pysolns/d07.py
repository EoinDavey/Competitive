import sys

inp = [int(x) for x in input().split(',')]

def partA():
  cs = sorted(inp)[::-1]
  ans = sum(cs)
  pos = 0
  lsum, rsum = 0, sum(cs)
  lsz, rsz = 0, len(cs)
  while len(cs) > 0:
    while len(cs) > 0 and pos >= cs[-1]:
      cs.pop()
      lsz += 1
      rsz -= 1
    pos += 1
    lsum += lsz
    rsum -= rsz
    ans = min(ans, lsum+rsum)
  print(ans)

def partB():
  ans = 10 ** 9
  apos = 0
  for pos in range(min(inp), max(inp)+1):
    cst = 0
    for x in inp:
     d = abs(x-pos)
     cst += (d * (d+1)) // 2
    if cst < ans:
      apos = pos
    ans = min(ans, cst)
  print(ans, apos)

partA()
partB()
