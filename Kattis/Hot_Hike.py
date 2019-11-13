n = int(input())
ts = *map(int, input().split()),

mn = max(ts)
d = 0
for i in range(n-2):
    scr = max(ts[i],ts[i+2])
    if scr < mn:
        mn = scr
        d = i

print(d+1, mn)
