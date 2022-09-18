N, K = [int(x) for x in input().split()]

def solve(k):
  if k == 0:
    return 0

  ex = solve(k-1)

  sm = 0
  for x in range(1, N+1):
    sm += max(x, ex)

  sm /= N

  return sm

print(solve(K))
