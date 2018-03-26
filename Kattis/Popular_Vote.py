T = input()
for _ in xrange(T):
    N = input()
    xs = [input() for _ in xrange(N)]
    mx = 0
    mind = 0
    for i,x in enumerate(xs):
        if x==mx:
            mind = -1
        elif x > mx:
            mx = x
            mind = i
    if mind < 0:
        print "no winner"
    elif mx > sum(xs)/2.0:
        print "majority winner %d" % (mind+1)
    else:
        print "minority winner %d" % (mind+1)

