from itertools import combinations
import bisect

lim = 10**18
classy = [lim]

def ev(ls):
    o = 0
    for l in ls:
        o = 10*o + l
    return o

def v(r):
    return bisect.bisect_right(classy, r)

for p in combinations(range(18), 3):
    s = [0]*18
    for i in xrange(1,10):
        s[p[0]] = i
        for j in xrange(1,10):
            s[p[1]] = j
            for k in xrange(1,10):
                s[p[2]] = k
                x = ev(s)
                if x <=lim:
                    classy.append(x)

for p in combinations(range(18), 2):
    s = [0]*18
    for i in xrange(1,10):
        s[p[0]] = i
        for j in xrange(1,10):
            s[p[1]] = j
            x = ev(s)
            if x <=lim:
                classy.append(x)

for p in xrange(18):
    s = [0]*18
    for i in xrange(1,10):
        s[p] = i
        x = ev(s)
        if x <=lim:
            classy.append(x)
classy.sort()

for _ in xrange(input()):
    l, r = map(int, raw_input().split())
    print v(r) - v(l-1)
