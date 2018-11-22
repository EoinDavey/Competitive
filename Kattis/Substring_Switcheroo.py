def slve(a,b):
    s = set()
    for i in xrange(len(b)):
        for j in xrange(i, len(b)):
            sb = b[i:j+1]
            sb = "".join(sorted(sb))
            s.add(sb)
    mx = 0
    ans = ""
    for i in xrange(len(a)):
        for j in xrange(i, len(a)):
            sa = a[i:j+1]
            sta = "".join(sorted(sa))
            if sta in s:
                if len(sa) > mx:
                    mx = len(sa)
                    ans = sa
    return ans


for _ in xrange(input()):
    a = raw_input()
    b = raw_input()
    c = slve(a,b)
    if c:
        print c
    else:
        print "NONE"
