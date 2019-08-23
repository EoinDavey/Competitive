n, m = [int(x) for x in input().split()]
A = [[int(x) for x in input().split()] for _ in range(n)]
B = [[0]*m for _ in range(n)]
ops = []
for x in range(n):
    for y in range(m):
        if not all([i >= 0 and j >= 0 and i < n and j < m and A[i][j] == 1 for i in [x,x+1] for j in [y,y+1]]):
            continue
        ops.append((x,y))
        for i, j in [(i, j) for i in [x,x+1] for j in [y, y+1]]:
            B[i][j] = 1

if all(A[i][j] == B[i][j] for i in range(n) for j in range(m)):
    print(len(ops))
    for x, y in ops:
        print(x+1,y+1)
else:
    print(-1)
