n = int(input())
ts = [int(x) for x in input().split()]
ss = [int(x) for x in input().split()]
ssorted = [i for i in range(n) if ss[i] != -1]

ssorted.sort(key=lambda x: ss[x])

def can_solve(pcs):
  t_ord = [ts[x] for x in ssorted]
  t_cum = []
  for x in t_ord:
    t_cum.append(x + (0 if len(t_cum) == 0 else t_cum[-1]))
  return all(t_cum[i] <= ss[ssorted[i]]*pcs for i in range(len(ssorted)))

L, R = 1, 10**10
while L < R:
  md = (L + R) // 2
  if can_solve(md):
    R = md
  else:
    L = md + 1
assert(can_solve(L))
print(L)
