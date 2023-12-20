from functools import lru_cache
M = 10**9 + 7

# f(x) = 3 * f(x-2) + 2*g(x-2)
# g(x) = f(x-2) + g(x-2)

def dot(x, y):
  return (x[0]*y[0] + x[1]*y[1]) % M

def matMult(A, B):
  BT = list(zip(*B))
  return [[dot(A[i], BT[j]) for j in [0,1]] for i in [0,1]]

def matPow(A, p):
  if p == 1:
    return A
  if p % 2 == 0:
    return matPow(matMult(A, A), p // 2)
  return matMult(A, matPow(A, p-1))

C = [[3,2], [1,1]]

for _ in range(int(input())):
  W = int(input())
  if W % 2 == 1:
    print(0)
    continue
  print(matPow(C, W // 2)[0][0])
