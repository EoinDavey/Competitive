import math
from collections import Counter
N = input()
ps = map(int, raw_input().split())
J = ps[0] + 1
ps = ps[1:]

c = Counter(ps)

ls = sorted(c.most_common())

y = ls[-1][0]
t = ls[-1][1]

ls.pop()

steps = 0

while len(ls):
  x = ls[-1][1]
  d = y - (ls[-1][0] + steps)

  jmp = 1 + int(math.floor(math.log(t,2)))

  ny = y + d*(jmp-1)

  if ny >= J:
    break

  ls.pop()

  steps += d*jmp
  t += x
  y = ny

if y < J:
  jmp = 1 + int(math.floor(math.log(t,2)))
  gp = jmp-1
  d = max(0, J-1-y)

  y += gp * (d/gp)
  steps += (d/gp)*jmp

  d = J-y
  steps += d


print steps - 1
