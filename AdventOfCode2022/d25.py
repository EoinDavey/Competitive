import sys

def lines():
  return [line.strip() for line in sys.stdin]

def v(c):
  if c in '012':
    return int(c)
  if c == '-':
    return -1
  return -2

def cnv(x):
  bs5 = []
  if x == 0:
    return 0
  while x:
    bs5.append(x % 5)
    x //= 5
  bs5.append(0)
  for i in range(len(bs5)-1):
    if bs5[i] < 3:
      continue
    bs5[i] = bs5[i] - 5
    bs5[i + 1] += 1
  if bs5[-1] == 0:
    bs5.pop()
  bs5.reverse()
  s = ''
  for i in range(len(bs5)):
    if bs5[i] >= 0:
      s += str(bs5[i])
    elif bs5[i] == -1:
      s += '-'
    else:
      s += '='
  return s

def partA():
  sm = 0
  for l in lines():
    s = l[::-1]
    for i, c in enumerate(s):
      sm += v(c) * (5 ** i)
  print(cnv(sm))

partA()
