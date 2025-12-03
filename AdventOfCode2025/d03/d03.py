import sys

def lines():
  return [line.strip() for line in sys.stdin]

banks = [[int(x) for x in y] for y in lines()]

def solve(digs):
  sm = 0
  for bank in banks:
    res = 0
    lb = 0
    for d in range(digs, 0, -1):
      dig = max(range(lb, len(bank) - (d - 1)), key = lambda x: bank[x])
      res = 10 * res + bank[dig]
      lb = dig + 1
    sm += res
  return sm

def partA():
  return solve(2)

def partB():
  return solve(12)

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
