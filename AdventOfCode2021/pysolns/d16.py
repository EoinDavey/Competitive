import sys
from itertools import islice
from functools import reduce

def lines():
  return [line.strip() for line in sys.stdin]

data = lines()[0]

def datastream():
  for x in data:
    v = int(x, base=16)
    for i in range(4)[::-1]:
      if (v & (1 << i)) != 0:
        yield 1
      else:
        yield 0

def binToInt(b):
  return int(''.join(str(x) for x in b), base=2)

def readPacket(data):
  hd = readHeader(data)
  if hd == None:
    return None
  v, t = hd
  if t == 4:
    n = readNumber(data)
    return {'v': v, 'tp': 'num', 'val': n}
  else:
    return {'v': v, 't': t, 'tp': 'op', 'op': readOp(data)}

def readHeader(data):
  vl = list(islice(data, 3))
  if len(vl) == 0:
    return None
  v = binToInt(vl)
  t = binToInt(islice(data, 3))
  return v, t

def readNumber(data):
  n = []
  while True:
    bs = list(islice(data, 5))
    n += bs[1:]
    if bs[0] == 0:
      break
  return binToInt(n)

def readOp(data):
  ltid = next(data)
  chs = []
  if ltid == 0:
    totalLen = binToInt(islice(data, 15))
    subSlice = list(islice(data, totalLen))
    subGen = (x for x in subSlice)
    while True:
      sp = readPacket(subGen)
      if sp == None:
        break
      chs.append(sp)
  else:
    nPackets = binToInt(islice(data, 11))
    for _ in range(nPackets):
      chs.append(readPacket(data))
  return chs

def sumVs(pckt):
  if pckt['tp'] == 'num':
    return pckt['v']
  sm = pckt['v']
  for sp in pckt['op']:
    sm += sumVs(sp)
  return sm

def calc(pckt):
  if pckt['tp'] == 'num':
    return pckt['val']
  t = pckt['t']
  cs = [calc(p) for p in pckt['op']]
  if t == 0:
    return sum(cs)
  if t == 1:
    return reduce(lambda x,y: x*y, cs, 1)
  if t == 2:
    return min(cs)
  if t == 3:
    return max(cs)
  if t == 5:
    return 1 if cs[0] > cs[1] else 0
  if t == 6:
    return 1 if cs[0] < cs[1] else 0
  return 1 if cs[0] == cs[1] else 0

def partA():
  print(sumVs(readPacket(datastream())))

def partB():
  print(calc(readPacket(datastream())))

partA()
partB()
