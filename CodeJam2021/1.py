T = int(input())
for t in range(T):
  N = int(input())
  ls = [int(x) for x in input().split()]

  cst = 0
  for i in range(N-1):
    j = min(range(i, N), key=lambda x: ls[x])
    cst += j - i + 1
    ls = ls[:i] + ls[i:j+1][::-1] + ls[j+1:]
  print(f'Case #{t + 1}: {cst}')
