import sys
n = input()
cs = map(int, raw_input().split())
cs.sort()

szs = range(1, n+1)
mn = 1.0
for i in xrange(n):
    if cs[i] > szs[i]:
        print "impossible"
        sys.exit(0)
    mn = min(mn, (cs[i]*1.0)/szs[i])
print mn
