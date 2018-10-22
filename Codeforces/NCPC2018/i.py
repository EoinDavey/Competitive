n, s = map(int, raw_input().split())

bets = [raw_input().split() for _ in xrange(n)]
bets = map(lambda x: (x[0], int(x[1])), bets)
bets.sort(key = lambda (a,b): (-b,a))
wnrs = []
for (a,b) in bets:
    if s and s >= b:
        s -= b
        wnrs.append(a)
if s:
    print "0"
else:
    print len(wnrs)
    print "\n".join(wnrs)
