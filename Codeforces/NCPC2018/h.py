l, m = map(int, raw_input().split())
week = 10080
mn = 1000*1000*1000
ans = []
for _ in xrange(m):
    ss = raw_input().split(",")
    p,c,t,r = map(int, ss[1:])
    rt = (c*t*week)/(t+r)
    if rt >= l:
        if p < mn:
            mn = p
            ans = [ss[0]]
        elif p==mn:
            ans.append(ss[0])
if len(ans) == 0:
    print "no such mower"
else:
    print "\n".join(ans)
