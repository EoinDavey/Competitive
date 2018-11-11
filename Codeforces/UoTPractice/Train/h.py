T = input()
for _ in xrange(T):
    n = input()
    hs = map(int, raw_input().split())
    mx = 0
    for i in xrange(1,2*n+1):
        mx = max(mx, hs[i-1] + hs[2*n - i])
    print mx
