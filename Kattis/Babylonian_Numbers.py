N = int(raw_input())

for _ in range(N):
    vals = map(lambda x: 0 if x=="" else int(x),raw_input().split(','))
    n = len(vals)
    sm =  0
    for i in range(n):
        sm+=vals[i]*(60**(n-i-1))
    print sm
