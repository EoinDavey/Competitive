import sys
from re import findall

INF = 10**9

def lines():
  return [line.strip() for line in sys.stdin]

l = [findall(r'[A-Z]', l) for l in lines()]
l1, l2 = l[2], l[3]
stcks = [[l2[x], l1[x]] for x in range(4)]

def hallIdx(stck):
  return 2 * (1 + stck)

def isRoomDoor(idx):
  return 0 < idx < 10 and idx % 2 == 0

def openHallSlots(hall, idx):
  s = []
  w = idx
  while w > 0 and hall[w-1] == '.':
    w -= 1
    s.append(w)
  w = idx
  while w < 10 and hall[w+1] == '.':
    w += 1
    s.append(w)
  return s

def movesToHall(hall, idx):
  return [pos for pos in openHallSlots(hall, idx) if not isRoomDoor(pos)]

def stackPseudoSolved(stcks, st):
  tgt = chr(ord('A') + st)
  return all(x == tgt for x in stcks[st])

def stackSolved(stcks, st, stackh):
  return len(stcks[st]) == stackh and stackPseudoSolved(stcks, st)

def solved(stcks, hall, stackh):
  s = all(stackSolved(stcks, st, stackh) for st in range(4))
  return s

def toKey(stcks, hall):
  return tuple([tuple([tuple(st) for st in stcks]), tuple(hall)])

costMp = {
    'A': 1,
    'B': 10,
    'C': 100,
    'D': 1000,
}

memo = {}
def tryMoves(stcks, hall, stackh):
  if solved(stcks, hall, stackh):
    return 0
  k = toKey(stcks, hall)

  if k in memo:
    return memo[k]

  ans = INF
  # Move from stacks to hall
  for st in range(4):
    if len(stcks[st]) == 0:
      continue
    if stackPseudoSolved(stcks, st):
      continue
    v = stcks[st][-1]
    hidx = hallIdx(st)
    hallPoss = movesToHall(hall, hidx)
    for h in hallPoss:
      hall[h] = v
      stcks[st].pop()

      subcst = tryMoves(stcks, hall, stackh)

      stcks[st].append(v)
      hall[h] = '.'

      mvcst = costMp[v] * (1 + stackh - len(stcks[st]) + abs(h - hidx))
      ans = min(ans, mvcst + subcst)

  # Move from hall to stacks
  for i, h in enumerate(hall):
    if h == '.':
      continue
    tgt = ord(h) - ord('A')
    hidx = hallIdx(tgt)
    if len(stcks[tgt]) == stackh:
      continue
    if not stackPseudoSolved(stcks, tgt):
      continue
    reachable = openHallSlots(hall, i)
    if hidx not in reachable:
      continue

    hall[i] = '.'
    stcks[tgt].append(h)
    subcst = tryMoves(stcks, hall, stackh)
    hall[i] = h
    stcks[tgt].pop()

    mvcst = costMp[h] * (abs(i - hidx) + stackh-len(stcks[tgt]))
    ans = min(ans, subcst + mvcst)

  memo[k] = ans
  return ans

def partA():
  print('Part 1:', tryMoves(stcks, ['.']*11, 2))

def partB():
  ls = ['DD', 'BC', 'AB', 'CA']
  for i in range(4):
    stcks[i] = [stcks[i][0]] + list(ls[i]) + [stcks[i][1]]
  print('Part 2:', tryMoves(stcks, ['.']*11, 4))

partA()
partB()
