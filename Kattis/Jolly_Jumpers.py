import sys
for line in sys.stdin:
    s = set()
    xs = map(int,line.split())[1:]
    for i in xrange(len(xs)-1):
        s.add(abs(xs[i]-xs[i+1]))
    if len(xs) <=1 or not set(range(1,len(xs)))-s:
        print "Jolly"
    else:
        print "Not jolly"
