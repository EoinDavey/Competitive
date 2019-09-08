n = int(input())
a = [int(x) for x in input().split()]

ind = max(range(n), key=lambda x:a[x])

fail = False
mn = a[ind]
for i in range(ind, n):
    if a[i] > mn:
        fail = True
        break
    mn = min(mn, a[i])

if not fail:
    mn = a[ind]
    for i in range(ind, -1, -1):
        if a[i] > mn:
            fail = True
            break
        mn = min(mn, a[i])
if fail:
    print("NO")
else:
    print("YES")
