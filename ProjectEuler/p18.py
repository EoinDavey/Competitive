triangle = [map(int,raw_input().split()) for _ in range(15)]

memo = [[-1]*i for i in range(1,16)]

def solve(x,y):
    global memo
    global triangle
    if memo[x][y] != -1:
        return memo[x][y]
    if x == 14:
        memo[x][y] = triangle[x][y]
        return triangle[x][y]
    left = solve(x+1,y)
    right = solve(x+1,y+1)
    memo[x][y] = triangle[x][y] + max(left,right)
    return memo[x][y]

print solve(0,0)
