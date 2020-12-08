import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = [line.split() for line in lines()]

def run(inp):
  acc = 0
  idx = 0
  seen = set()
  while True:
    if idx in seen:
      return acc, False
    if idx == len(inp):
      return acc, True
    seen.add(idx)
    op, inc = inp[idx][0], int(inp[idx][1])
    if op == "acc":
      acc += inc
      idx += 1
    elif op == "jmp":
      idx += inc
    elif op == "nop":
      idx += 1

def partA():
  print(run(inp)[0])

def partB():
  for i in range(len(inp)):
    op = inp[i][0]
    if op == "acc":
      continue
    newop = "jmp" if op == "nop" else "nop"
    inp[i][0] = newop
    val, halt = run(inp)
    inp[i][0] = op
    if halt:
      print(val)
      return

partA()
partB()
