from fractions import Fraction

rSet = set()

for i in xrange(1,1019):
    for j in xrange(1,i+1):
        rSet.add(Fraction(i,j))

print len(rSet)
