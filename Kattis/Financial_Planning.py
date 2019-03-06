n, M = map(int, raw_input().split())
ls = [map(int, raw_input().split()) for _ in xrange(n)]

l = []
for p, c in ls:
  t = (c+p-1)/p
  d = p*t - c
  assert(d >= 0)
  l.append((t,d,p))

l.sort(reverse=True)

dly = 0
dys = 0
tot = 0

while tot < M and len(l):
  nt, nd, np = l.pop()
  if dly:
    gp = M-tot
    tm = (gp+dly-1)/dly
    if tm + dys <= nt:
      dys += tm
      tot += dly*tm
      assert(tot >= M)
      break
    else:
      stp = nt-dys
      dys += stp
      tot += dly*stp
  assert(tot < M)
  dly += np
  tot += nd
  dys = nt

gp = max(0, M-tot)
tm = (gp+dly-1)/dly
dys += tm
tot += dly*tm

print dys
