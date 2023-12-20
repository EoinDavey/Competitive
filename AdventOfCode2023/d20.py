import sys
from collections import deque, defaultdict

def lines():
  return [line.strip() for line in sys.stdin]
def parse():
  out = []
  for l in lines():
    i, o = l.split(' -> ')
    o = o.split(', ')
    tp = 'b' if i == 'broadcaster' else 'f' if i[0] == '%' else 'c'
    i = i[1:] if tp in 'fc' else i
    out.append((i, (tp, o)))
  return dict(out)
INP = parse()

def partA():
  inps = defaultdict(list)
  for i, (tp, o) in INP.items():
    for v in o:
      if v in INP and INP[v][0] == 'c':
        inps[v].append(i)

  cst = {}
  for i, (tp, o) in INP.items():
    if tp != 'c':
      continue
    cst[i] = {}
    for v in inps[i]:
      cst[i][v] = False
  fst = defaultdict(int)
  sms = [0, 0]
  for _ in range(1000):
    q = deque([('button', 0, 'broadcaster')])
    while q:
      orgn, lvl, d = q.popleft()
      sms[lvl] += 1
      if d not in INP:
        continue
      tp, o = INP[d]
      if tp == 'b':
        for v in o:
          q.append((d, lvl, v))
        continue
      if tp == 'f':
        if lvl == 1:
          continue
        fst[d] = 1-fst[d]
        for v in o:
          q.append((d, fst[d], v))
        continue
      assert(tp == 'c')
      cst[d][orgn] = lvl
      ol = 0 if all(cst[d].values()) else 1
      for v in o:
        q.append((d, ol, v))
  print(sms[0] * sms[1])

def partB():
  # ad hoc manual check
  # rx low iff rg inps all high
  # kd, zf, vg, gs all high out
  # 
  # kd 1 iff prs % 3767 == 0
  # zf 1 iff prs % 3779 == 0
  # vg 1 iff prs % 4057 == 0
  # gs 1 iff prs % 3889 == 0
  pass

partA()
