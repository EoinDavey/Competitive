for _ in xrange(input()):
    n,x,y,d = map(int, raw_input().split())
    mn = 10**18
    if abs(y-x)%d==0:
        mn = min(mn, abs(y-x)/d)
    if (y-1)%d==0:
        mn = min(mn, ((x-1)+(d-1))/d + (y-1)/d)

    if (n-y)%d==0:
        mn = min(mn, ((n-x)+(d-1))/d + (n-y)/d)

    if mn > 10**10:
        print -1
    else:
        print mn
