import sys
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

ts = int(input())
buses = input().split(',')

def partA():
  valid = [int(x) for x in buses if x != "x"]
  mn = min(valid, key = lambda x: x - (ts % x))
  print(mn * (mn - (ts % mn)))

def partB():
  inp = [(int(buses[i]), -i % int(buses[i])) for i in range(len(buses)) if buses[i] != "x"]
  N = reduce(lambda x, y: x * y[0], inp, 1)
  Ni = [N // a for a, b in inp]
  z = [pow(Ni[i], inp[i][0] - 2, N) for i in range(len(inp))]
  print(sum([(inp[i][1] * Ni[i] * z[i]) % N for i in range(len(inp))]) % N)

partA()
partB()
