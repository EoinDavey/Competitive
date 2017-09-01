T = int(raw_input())
for _ in range(T):
    n = int(raw_input())
    d = {}
    for _ in range(n):
        [_,b] = raw_input().split()
        if b in d:
            d[b]+=1
        else:
            d[b] = 1
    sm = 1
    for k in d.values():
        sm*=(k+1)
    print sm-1
