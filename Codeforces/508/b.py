import sys
n = input()

if n <= 2:
    print "No"
    sys.exit(0)
else:
    print "Yes"

s = sum(range(1, n+1))

fac = 0
for x in xrange(2, s+1):
    if s%x==0:
        fac = x
        break

a = []
b = []

for x in xrange(1, n+1):
    if x%fac==0:
        a.append(x)
    else:
        b.append(x)
print len(a),
print ' '.join(map(str, a))
print len(b),
print ' '.join(map(str, b))
