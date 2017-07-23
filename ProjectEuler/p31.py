coins = [1,2,5,10,20,50,100,200]
target = 200

ways = [[0]*len(coins) for _ in range(201)]

for i in range(len(coins)):
    ways[0][i] = 1

for i in range(1,201):
    for j in range(len(coins)):
        ways[i][j] = (ways[i][j-1] if j > 0 else 0) + (ways[i-coins[j]][j] if i >= coins[j] else 0)

print ways[200][len(coins)-1]
