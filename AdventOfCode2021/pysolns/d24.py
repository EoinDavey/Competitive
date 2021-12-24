import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

class Op:
  def __init__(self, op, l, r):
    self.op = op
    self.l = l
    self.r = r

def isReg(v):
  return v in list('xyzw')

def regIdx(v):
  return ord(v) - ord('w')

coms = [l.split() for l in lines()]
for i in range(len(coms)):
  for j in range(1, len(coms[i])):
    if not isReg(coms[i][j]):
      coms[i][j] = int(coms[i][j]);

def simplify(op):
  com, l, r = op.op, op.l, op.r
  if com == "mul":
    if l == 0 or r == 0:
      return 0
    if l == 1:
      return r
    if r == 1:
      return l
  if com == "add":
    if l == 0:
      return r
    if r == 0:
      return l
    if isinstance(l, int) and isinstance(r, int):
      return l + r
  if com == "mod":
    if l == 0:
      return 0
    if r == 1:
      return l
  if com == "div":
    if l == 0:
      return 0
    if r == 1:
      return l
  return op

def buildTree(coms):
  inCnt = 0
  regs = [0] * 4
  simpleComs = []
  for i, c in enumerate(coms):
    if c[0] == 'inp':
      regs[regIdx(c[1])] = f'x_{inCnt}'
      simpleComs.append(coms[i])
      inCnt += 1
      continue
    c, l, r = c
    lidx = regIdx(l)
    l = regs[lidx]
    if isReg(r):
      r = regs[regIdx(r)]
    op = simplify(Op(c, l, r))
    if regs[lidx] != op:
      simpleComs.append(coms[i])
    regs[lidx] = op
  return regs, simpleComs

def identifyBlocks(coms):
  blcks = []
  blck = []
  for line in coms:
    if line[0] == "inp":
      if blck:
        blcks.append(blck)
      blck = []
    blck.append(line)
  blcks.append(blck)
  blocksOut = []
  for i, blck in enumerate(blcks):
    form = 1
    if any(com[0] == "div" for com in blck):
      form = 2
    dx = None
    for com in blck:
      if com[0] == 'add' and com[1] == 'x' and com[2] != 'z':
        dx = int(com[2])
    assert dx != None
    dycom = blck[-3]
    assert dycom[0] == "add" and dycom[1] == "y"
    dy = int(dycom[2])
    blocksOut.append((form, dx, dy))
    print(form, dx, dy)
  return blocksOut

def findSoln(blcks, z, idx, mx=True):
  if idx >= len(blcks):
    return 0 if z == 0 else None

  frm, dx, dy = blcks[idx]

  if frm == 1:
    for iv in (range(9, 0, -1) if mx else range(1, 10)):
      nz = 26 * z + (iv + dy)
      sub = findSoln(blcks, nz, idx + 1, mx)
      if sub != None:
        return sub + (iv * 10 ** (len(blcks) - 1 - idx))
    return None

  t = dx + (z % 26)
  if t < 1 or t > 9:
    return None
  nz = z // 26
  if (sub := findSoln(blcks, nz, idx + 1, mx)) != None:
      return sub + (t * 10 ** (len(blcks) - 1 - idx))
  return None

regs, simpleComs = buildTree(coms)
blocks = identifyBlocks(simpleComs)

def partA():
  print('Part 1:', findSoln(blocks, 0, 0))

def partB():
  print('Part 2:', findSoln(blocks, 0, 0, mx=False))

partA()
partB()
