import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = [int(l) for l in lines()]

def partA():
  print(len([(a,b) for (a, b) in zip(inp, inp[1:]) if b > a]))

def partB():
  print(len([(a,b) for (a, b) in zip(range(len(inp) - 2), range(1, len(inp) - 2)) if sum(inp[b:b+3]) > sum(inp[a:a+3])]))

partA()
partB()
