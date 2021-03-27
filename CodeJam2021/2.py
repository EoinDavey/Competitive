from collections import defaultdict

INF = 10**9

def solve(x, y, s):
  memo = defaultdict(lambda: defaultdict(lambda: INF))

  c = s[0]
  if c in ['C', '?']:
    memo[0]['C'] = 0
  if c in ['J', '?']:
    memo[0]['J'] = 0

  for i in range(1, len(s)):
    c = s[i]
    pc = memo[i-1]['C'] if i > 0 else 0
    pj = memo[i-1]['J'] if i > 0 else 0

    if c in ['C', '?']:
      memo[i]['C'] = min(pc, Y + pj)
    if c in ['J', '?']:
      memo[i]['J'] = min(pj, X + pc)
  return min(memo[len(s) - 1].values())

T = int(input())

for t in range(T):
  X, Y, S = input().split()
  X, Y = int(X), int(Y)
  ans = solve(X, Y, S)
  print(f'Case #{t+1}: {ans}')
