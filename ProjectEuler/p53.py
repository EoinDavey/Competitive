N = 101
dp = [[0]*N for _ in range(N)]

for i in range(N):
    dp[i][0] = 1

for i in range(1,N):
    for j in range(1,i+1):
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

cnt = 0
for i in range(N):
    for j in range(N):
        if dp[i][j] > 1000000:
            cnt+=1
print cnt
