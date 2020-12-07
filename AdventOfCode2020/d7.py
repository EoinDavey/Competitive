import sys
from collections import defaultdict, deque

def lines():
  return [line.strip() for line in sys.stdin]

grph = defaultdict(list)
revgrph = defaultdict(list)
colours = set()

for line in lines():
  words = line.split()
  colour = words[0] + " " + words[1]
  colours.add(colour)
  contents = words[4:]
  if contents[0] == "no":
    continue
  while len(contents) >= 3:
    n, c1, c2, _ = contents[:4]
    col = c1 + " " + c2
    n = int(n)
    grph[col].append((n, colour))
    revgrph[colour].append((n, col))

    contents = contents[4:]

def partA():
  q = deque(['shiny gold'])
  vis = set(['shiny gold'])
  while q:
    v = q.popleft()
    for _, v in grph[v]:
      if v not in vis:
        vis.add(v)
        q.append(v)
  print(len(vis) - 1)

def partB():
  def rec(v):
    return 1 + sum([n * rec(u) for n, u in revgrph[v]])
  print(rec('shiny gold') - 1)

partA()
partB()
