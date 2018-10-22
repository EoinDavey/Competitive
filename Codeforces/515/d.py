n, m, k = map(int, raw_input().split())
a = map(int, raw_input().split())
a = a[::-1]
sz = 0
bxs = 0

mx = 0

for ind, i in enumerate(a):
    if i+sz <=k:
        sz+=i
    else:
        if sz:
            bxs+=1
        sz = i
    if bxs + (1 if sz else 0) <= m:
        mx = ind
    else:
        break

if bxs + (1 if sz else 0) <= m:
    mx = ind
print mx+1
