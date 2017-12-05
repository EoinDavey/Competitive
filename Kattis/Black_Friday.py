import collections
n = input()
xs = map(int,raw_input().split())
indmp = {xs[i]:i for i in xrange(len(xs))}
c = collections.Counter(xs)
m = map(lambda x:x[0],filter(lambda (a,b):b==1,c.iteritems()))
if len(m) > 0:
    print indmp[max(m)]+1
else:
    print "none"
