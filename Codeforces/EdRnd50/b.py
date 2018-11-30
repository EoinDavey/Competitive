for _ in xrange(input()):
    n, m, k = map(int, raw_input().split())
    if k < max(n, m):
        print -1
        continue
    diags = min(n,m)
    n -= diags
    m -= diags
    k-= diags
    rem = n+m
    k -= rem
    diags += rem
    rem %= 2
    if rem:
        diags += k-1
    else:
        if k%2==0:
            diags += k
        else:
            diags += 2*(k/2) - 1
    print diags
