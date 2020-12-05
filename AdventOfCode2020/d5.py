import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()

ids = []
for line in inp:
  line = line.replace('F', '0')
  line = line.replace('B', '1')
  line = line.replace('L', '0')
  line = line.replace('R', '1')
  ids.append(int(line, 2))

def partA():
  print(max(*ids))

def partB():
  s = set(ids)
  for i in range(1, 2 ** 10 - 1):
    if i not in s and (i-1) in s and (i+1) in s:
      print(i)

partA()
partB()
