import sys

def lines():
  return [line.strip() for line in sys.stdin]

inp = [x.split() for x in lines()]
inp = [(x[0], x[2]) if x[0] == "mask" else (int(x[0][4:-1]), int(x[2])) for x in inp]

def appMask(mask, dnum):
  for i in range(len(mask)):
    idx = len(mask) - i - 1
    if mask[idx] == 'X':
      continue
    if mask[idx] == '1':
      dnum |= 2 ** i
    if mask[idx] == '0':
      if (dnum & (2 ** i)) != 0:
        dnum -= 2 ** i
  return dnum

def allAddr(mask, val):
  xs = len([x for x in mask if x == 'X'])

  vals = []
  for st in range(2 ** xs):
    msk = []
    for i in range(len(mask)):
      if mask[i] == 'X':
        msk.append('0' if st % 2 == 0 else '1')
        st //= 2
      elif mask[i] == '1':
        msk.append('1')
      else:
        msk.append('X')
    vals.append(appMask(msk, val))
  return vals

def partA():
  mask = ""
  mem = {}
  for a, b in inp:
    if a == "mask":
      mask = b
      continue
    b = appMask(mask, b)
    mem[a] = b
  sm = 0
  for k in mem:
    sm += mem[k]
  print(sm)

def partB():
  mask = ""
  mem = {}
  for a, b in inp:
    if a == "mask":
      mask = b
      continue
    addrs = allAddr(mask, a)
    for addr in addrs:
      mem[addr] = b
  sm = 0
  for k in mem:
    sm += mem[k]
  print(sm)

partA()
partB()
