N = int(input())
tgrs = [int(x) for x in input().split()]
Q = int(input())
for _ in range(Q):
    L, R = *map(int, input().split()),
    cnt = 0
    for x in tgrs:
        if L <= x <= R:
            cnt += 1 
    print(cnt)
