n = int(input())
a = [int(x) for x in input().split()]

dpn = 1 if a[0] < 0 else 0
dpp = 1 - dpn

ng, ps = dpn, dpp
for i in range(1, n):
    if a[i] > 0:
        dpp += 1
    else:
        dpn, dpp = dpp + 1, dpn

    ng += dpn
    ps += dpp

print(ng, ps)
