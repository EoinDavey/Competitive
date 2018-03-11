MX =25002

'''
for a in xrange(1,MX):
    for b in xrange(a+1,MX):
        s1.add((max(a,b),a**3 + b**3 - 1))
print "f"

for c in xrange(MX):
    for (m,v) in s1:
        l=c**3
        if c > m and l == v:
            s2.add(c)

'''
cbs = set()
iscube = set()
for c in xrange(1,MX):
    cbs.add((c,c**3))
    iscube.add(c**3)

lst = []
i = 0
for (c,c3) in cbs:
    i += 1
    for (a,a3) in cbs:
        if a3 >= c3:
            continue
        b3 = c3 - a3 + 1
        if b3 not in iscube:
            continue
        if b3 > a3 and c3 > b3:
            lst.append(c)
print sorted(lst)
