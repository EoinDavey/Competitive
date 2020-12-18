import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()

class Parser():
  def __init__(self, expr, prec):
    self.expr = expr
    self.len = len(expr)
    self.idx = 0
    self.prec = prec

  def _(self):
    while self.idx < self.len and self.expr[self.idx] == ' ':
      self.idx += 1

  def atom(self):
    if self.idx < self.len and self.expr[self.idx] == '(':
      self.idx += 1
      val = self.solvePrec() if self.prec else self.solveNoPrec()
      self._()
      self.idx += 1
      return val
    return self.num()

  def num(self):
    num = ""
    while self.idx < self.len and '0' <= self.expr[self.idx] <= '9':
      num += self.expr[self.idx]
      self.idx += 1
    return int(num)

  def solvePrec(self):
    return self.solveWith("*", lambda: self.solveWith("+", self.atom))

  def solveNoPrec(self):
    return self.solveWith("+*", self.atom)

  def solveWith(self, ops, sub):
    self._()
    num = sub()

    while self.idx < self.len:
      self._()
      op = self.expr[self.idx]
      if not op in ops:
        break
      self.idx += 1
      self._()
      val = sub()
      if op == "+":
        num += val
      else:
        num *= val
    return num

  def solve(self):
    return self.solvePrec() if self.prec else self.solveNoPrec()

def solveAll(inp, prec):
  return sum([Parser(x, prec).solve() for x in inp])

def partA():
  print(solveAll(inp, False))

def partB():
  print(solveAll(inp, True))

partA()
partB()
