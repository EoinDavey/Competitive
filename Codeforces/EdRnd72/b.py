for _ in range(int(input())):
    n, x = *map(int, input().split()),

    inp = [[int(x) for x in input().split()] for _ in range(n)]

    dlt = [a[1] - a[0] for a in inp]

    bs = max(map(lambda x: x[0], inp))
    x -= bs
    if x <= 0:
        print(1)
        continue
    
    mnD = min(dlt)

    if mnD >= 0:
        print(-1)
        continue

    mnD *= -1

    print(1 + (x + mnD - 1)//mnD)
