from math import sqrt

N, R = *map(int, input().split()),

crcs = [[float(x) for x in input().split()] for _ in range(N)]
crcs.append([-R, 0, 0])
crcs.append([R, 0, 0])

N += 2

def dist(a, b):
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2))

sts = [set([i]) for i in range(N)]
sti = [i for i in range(N)]
for i in range(N):
    for j in range(i):
        if dist(crcs[i], crcs[j]) <= crcs[i][2] + crcs[j][2]:
            iind = sti[i]
            jind = sti[j]
            if iind == jind:
                continue
            for x in sts[jind]:
                sts[iind].add(x)
                sti[x] = iind
            sts[jind] = set()

cnt = 0
for x in range(N):
    if sts[x]:
        cnt += 1
print(cnt - 1)
