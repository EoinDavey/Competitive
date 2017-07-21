N = 21
memo = [[-1]*N for _ in range(N)]

def solve(x,y):
    global memo
    if memo[x][y] != -1:
        return memo[x][y]
    if x==N-1 and y==N-1:
        memo[x][y] = 1
        return 1
    memo[x][y] = (solve(x+1,y) if x < N-1 else 0) + (solve(x,y+1) if y < N-1 else 0)
    return memo[x][y]

print solve(0,0)
