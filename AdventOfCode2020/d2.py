import sys

lines = [line.strip().split(' ') for line in sys.stdin]
inp = [[int(x) for x in line[0].split('-')] + [line[1][:-1], line[2]] for line in lines]

def partA():
  cnt = 0
  for [l, u, c, p] in inp:
    if l <= p.count(c) <= u:
      cnt += 1
  print(cnt)

def partB():
  cnt = 0
  for [l, u, c, p] in inp:
    if (p[l - 1] == c) != (p[u - 1] == c):
      cnt += 1
  print(cnt)

partA()
partB()
