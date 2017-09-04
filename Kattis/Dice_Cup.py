[N,M] = map(int,raw_input().split())

d = {}
for i in range(1,N+1):
    for j in range(1, M+1):
        if i+j in d:
            d[i+j]+=1
        else:
            d[i+j] = 1

v = d.items()
m = max(d.values())
v.sort()
for (a,b) in v:
    if b==m:
        print a
