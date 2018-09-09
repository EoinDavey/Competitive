H, W = map(int, raw_input().split())

g = [map(int, raw_input().split()) for _ in range(H)]

mvs = []
for i in xrange(H):
    r = range(W) if i % 2 == 0 else range(W)[::-1]
    mv = 1 if i%2==0 else -1
    for j in r:
        if g[i][j] % 2 == 0:
            continue
        if 0<=j+mv and j+mv < W:
            g[i][j] -=1
            g[i][j+mv] +=1

            mvs.append((i+1,j+1,i+1,j+mv+1))
        elif i+1 < H:
            g[i][j] -= 1
            g[i+1][j] += 1
            mvs.append((i+1,j+1,i+2,j+1))

print len(mvs)
for m in mvs:
    print "%d %d %d %d" % m
