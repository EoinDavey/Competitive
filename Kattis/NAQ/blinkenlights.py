p,q,s = map(int,raw_input().split())
b = False
for t in xrange(1,s+1):
    if t % p==0 and t%q == 0:
        print "yes"
        b = True
        break
if not b:
    print "no"
