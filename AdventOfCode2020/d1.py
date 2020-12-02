import sys

xs = []
for line in sys.stdin:
  line.strip()
  xs.append(int(line))

def part1():
  for i in range(len(xs)):
    a = xs[i]
    for j in range(i):
      b = xs[j]
      if a + b == 2020:
        print(a * b)

def part2():
  for i in range(len(xs)):
    a = xs[i]
    for j in range(i):
      b = xs[j]
      for k in range(j):
        c = xs[k]
        if a + b + c == 2020:
          print(a * b * c)

part1()
part2()
