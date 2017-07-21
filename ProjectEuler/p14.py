def nxt(n):
    if n%2==0:
        return n/2
    return 3*n + 1

N = 1000000
memo = {}

def solve(x):
    if x == 1:
        return 1
    if x in memo:
        return memo[x]
    memo[x] = 1 + solve(nxt(x))
    return memo[x]

mx = 0
ans = 0
for x in range(1,N):
    c = solve(x)
    if c > mx:
        mx = c
        ans = x
print ans
