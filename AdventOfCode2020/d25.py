import sys

p1, p2 = int(input()), int(input())

def partA():
  s = 7
  v = 1
  ls1 = 0
  while v != p1:
    v = (v * s) % 20201227
    ls1 += 1
  v = 1
  s = p2
  for _ in range(ls1):
    v = (v * s) % 20201227
  print(v)

def partB():
  pass

partA()
partB()
