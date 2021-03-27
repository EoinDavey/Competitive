def guess(*args):
  print(*args, flush=True)
  return int(input())

def correct(ls, ub):
  if len(ls) < 2:
    return ls
  a, b = ls[:2]
  ans = guess(a, b, ub)
  if ans == b:
    return ls
  return ls[::-1]

def triSplit(ls):
  # <l> a <m> b <r>
  if len(ls) < 2:
    return ls
  a, b = ls[:2]
  l, m, r = [], [], []
  for x in ls[2:]:
    ans = guess(a, b, x)
    if ans == a:
      l.append(x)
    elif ans == b:
      r.append(x)
    elif ans == x:
      m.append(x)
  l = correct(triSplit(l), a)
  m = correct(triSplit(m), b)
  r = correct(triSplit(r), b)[::-1]
  return l + [a] + m + [b] + r

T, N, _ = [int(x) for x in input().split()]

for _ in range(T):
  ls = triSplit(list(range(1, N + 1)))
  guess(*ls)
