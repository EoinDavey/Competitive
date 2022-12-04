import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP=lines()

def priority(c):
  if 'A' <= c <= 'Z':
    return 27 + ord(c) - ord('A')
  return 1 + ord(c) - ord('a')

def partA():
  sm = 0
  for l in INP:
    a, b = l[:len(l)//2], l[len(l)//2:]
    sm += priority(list(set(a) & set(b))[0])
  print(sm)

def partB():
  sm = 0
  for i in range(0, len(INP), 3):
    sm += priority(list(set(INP[i]) & set(INP[i+1]) & set(INP[i+2]))[0])
  print(sm)

partA()
partB()
