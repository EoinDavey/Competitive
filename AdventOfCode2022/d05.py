import sys

def lines():
  return [line.rstrip() for line in sys.stdin]

INP = lines()
gap = INP.index("")
stackInp = INP[:gap-1]
nStacks = int(INP[gap-1].split()[-1])
STACKS = {i: [] for i in range(1, nStacks+1)}

mvInp = INP[gap+1:]
MOVES = []
for l in mvInp:
  s = l.split()
  MOVES.append((int(s[1]), int(s[3]), int(s[5])))

for l in stackInp[::-1]:
  for s in range(nStacks):
    idx = 1 + s*4
    if idx >= len(l) or l[idx]==' ':
      continue
    STACKS[s+1].append(l[idx])

def partA():
  stcks = {}
  for k, v in STACKS.items():
    stcks[k] = v[:]
  for (m, a, b) in MOVES:
    for _ in range(m):
      stcks[b].append(stcks[a].pop())
  print(''.join([stcks[i][-1] for i in range(1, nStacks+1)]))

def partB():
  stcks = {}
  for k, v in STACKS.items():
    stcks[k] = v[:]
  for (m, a, b) in MOVES:
    hold=[]
    for _ in range(m):
      hold.append(stcks[a].pop())
    for _ in range(m):
      stcks[b].append(hold.pop())
  print(''.join([stcks[i][-1] for i in range(1, nStacks+1)]))

partA()
partB()
