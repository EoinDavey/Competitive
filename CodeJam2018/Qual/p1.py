def val(s):
    o = 1
    d = 0
    for c in s:
        if c=="C":
            o*=2
        else:
            d+=o
    return d
            
for _t in xrange(1,input()+1):
    l = raw_input().split()
    D = int(l[0])
    P = list(l[1])

    cnt = 0
    while val(P) > D:
        b = False
        for i in xrange(len(P)-1,0,-1):
            if P[i] == "S" and P[i-1] == "C":
                P[i], P[i-1] = P[i-1],P[i]
                b = True
                cnt+=1
                break
        if not b:
            break
    if val(P) > D:
        print "Case #%d: IMPOSSIBLE" % _t
    else:
        print "Case #%d: %d"  %(_t,cnt)
