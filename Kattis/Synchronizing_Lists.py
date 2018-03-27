while 1:
    N = input()
    if not N:
        break
    a = [input() for _ in xrange(N)]
    aS = sorted(a)
    b = [input() for _ in xrange(N)]
    mp = {}
    bs = sorted(b)
    for i,x in enumerate(bs):
        mp[aS[i]]=x
    for x in a:
        print mp[x]
    print ""
