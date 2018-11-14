import math
for _ in xrange(input()):
    d = float(input())
    if d*d - 4*d < 0:
        print "N"
    else:
        a = (d - math.sqrt(d*d - 4.0*d))/2.0
        b = d-a
        print 'Y',a,b
