import sys
t = 1
for line in sys.stdin:
    xs = map(int,line.split())[1:]
    print "Case %d: %d %d %d" %(t,min(xs),max(xs),max(xs)-min(xs))
    t+=1

