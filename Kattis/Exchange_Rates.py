while 1:
    d = input()
    if not d:
        break
    ls = [input() for _ in xrange(d)]
    mxcan = 100000
    mxusd = 0
    for r in ls:
        mxcan, mxusd = max(mxcan,int(mxusd*r*0.97)), max(mxusd,int(mxcan*0.97/r))
    print "%.2f" % (mxcan/100.0)
