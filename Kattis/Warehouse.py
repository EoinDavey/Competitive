for _ in xrange(input()):
    N = input()
    ls = [raw_input().split() for _ in xrange(N)]
    cnt = {}
    for l in ls:
        a,b = l
        b=int(b)
        if a in cnt:
            cnt[a]+=b
        else:
            cnt[a]=b
    l = cnt.items()
    l.sort(key=lambda (a,b): (-b, a))
    print len(l)
    for a,b in l:
        print a, b
