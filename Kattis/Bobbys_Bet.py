def ncr(n, r):
    o = 1
    for i in xrange(n, n-r, -1):
        o *= i
    for i in xrange(1, r+1):
        o /= i
    return o

def bernoulli(y, x, p):
    q = 1-p
    o = 0.0
    for i in xrange(x, y+1):
        o += ncr(y, i) * (p**i) * (q**(y-i))
    return o

def ans(R, S, X, Y, W):
    p = ((S-R+1)*1.0)/S
    prob = bernoulli(Y, X, p)
    ex = prob*W
    if ex > 1.0:
        print "yes"
    else:
        print "no"

map(lambda x: ans(*x), [map(int, raw_input().split()) for _ in xrange(input())])
