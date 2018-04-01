T = input()
for _t in xrange(T):
    D, N = map(int,raw_input().split())
    hs = [map(int,raw_input().split()) for _ in xrange(N)]
    hs.sort(key = lambda h:h[0],reverse=True)

    def nT(t,(k,s)):
        eta = (D-k)/(1.0*s)
        if k > D or eta < t:
            return t
        return eta

    t = reduce(nT,hs,0)
    print "Case #%d: %.8f" % (_t+1,D/t)
