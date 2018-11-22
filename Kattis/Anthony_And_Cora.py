n, m = map(int, raw_input().split())
ps = [float(raw_input()) for _ in xrange(n+m-1)]
tot = n+m

memo = {}
def f(p, cr):
    if (p,cr) in memo:
        return memo[(p,cr)]
    if p==0:
        return 0
    if cr==0:
        return 1.0
    r = tot-p-cr

    ans = ps[r] * f(p, cr-1) + (1-ps[r]) * f(p-1, cr)
    memo[(p,cr)] = ans
    return ans

print "%.8f" % f(n, m)
