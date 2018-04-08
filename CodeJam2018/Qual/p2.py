for _t in xrange(1,input()+1):
    N = input()
    xs = map(int,raw_input().split())
    evs = sorted(xs[::2])
    ods = sorted(xs[1::2])
    out = [0]*N
    for i in xrange(N):
        if i%2==0:
            out[i]=evs[i/2]
        else:
            out[i]=ods[i/2]
    fail = False
    for i in xrange(N-1):
        if out[i] > out[i+1]:
            fail=True
            print "Case #%d:"%_t, i
            break
    if not fail:
        print "Case #%d: OK" % _t
