def construct(N, cst):
  if N == 0:
    return []
  tgt = min(cst - (N - 1), N)
  subls = [x + 1 for x in construct(N - 1, cst - tgt)]
  return subls[:tgt-1][::-1] + [1] + subls[tgt-1:]

T = int(input())
for t in range(T):
  N, C = [int(x) for x in input().split()]
  C += 1
  if C < N or C > (N * (N+1)) // 2:
    print(f'Case #{t+1}: IMPOSSIBLE')
    continue
  ls = construct(N, C)
  print(f'Case #{t+1}: {" ".join([str(x) for x in ls])}')
