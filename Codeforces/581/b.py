def fill(x):
    return [2**i for i in xrange(x)]

n, l, r = map(int, raw_input().split())

mn = sum(fill(l)) + (n-l)
mx = sum(fill(r)) + (2**(r-1))*(n-r)
print mn, mx
