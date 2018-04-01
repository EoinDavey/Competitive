T = input()
for _t in xrange(T):
    N = input()
    P = map(int,raw_input().split())
    out = []

    while 1:
        c = len(filter(lambda x: x > 0,P))
        if c==0:
            break
        if c > 2:
            mx = max(range(N),key=lambda x: P[x])
            P[mx]-=1
            out.append("%c" % chr(mx+65))
        else:
            p = filter(lambda x: P[x] > 0,range(N))
            if P[p[0]] == P[p[1]]:
                P[p[0]]-=1
                P[p[1]]-=1
                out.append("%c%c" % (chr(p[0]+65),chr(p[1]+65)))
            elif P[p[0]] > P[p[1]]:
                P[p[0]]-=1
                out.append("%c" % chr(p[0]+65))
            else:
                P[p[1]]-=1
                out.append("%c" % chr(p[1]+65))
    print "Case #%d:" % (_t+1), " ".join(out)
