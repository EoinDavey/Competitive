import sys
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

inp = [l.split() for l in lines()]

def partA():
  print(sum([int(b) for (a, b) in inp if a.startswith('forward')]) * (
        sum([int(b) for (a, b) in inp if a.startswith('down')]) -
        sum([int(b) for (a, b) in inp if a.startswith('up')])))

def partB():
  def r(f1, f2):
    (a, h, d), (c, x) = f1, f2
    return (a+int(x), h, d) if c.startswith('down') else (
      (a-int(x), h, d) if c.startswith('up') else (
      (a, h + int(x), d + a*int(x))))

  print(x := reduce(r, inp, (0, 0, 0)), x[1] * x[2])

partA()
partB()
