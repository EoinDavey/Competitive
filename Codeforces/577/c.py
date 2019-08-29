n, k = *map(int, input().split()),
a = [int(x) for x in input().split()]
a.sort()
md = n//2

wnl = 1
ub = a[md+wnl] if md + wnl < n else 10**10
v = a[md]

while k:
    while md + wnl < n:
        if a[md+wnl] != v:
            break
        wnl += 1

    ub = a[md+wnl] if md + wnl < n else 10**10

    gp = ub - v
    tms = min(k//wnl, gp)

    if not tms:
        break

    k -= wnl * tms
    v += tms

print(v)
