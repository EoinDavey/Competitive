n, c, b = map(int, raw_input().split())
zs =  map(lambda x: int(x)-1, raw_input().split())
prs = zip(zs, zs[1:])

o = [0]*n

for a,b in prs:
    for i in xrange(a+1, b, 2):
        if c >= 2:
            o[i] = 1
            c-=2

if c % 2 == 0:
    for i in xrange(1, zs[0], 2):
        if c >= 2:
            o[i] = 1
            c-=2
else:
    o[0] = 1
    c-=1
    for i in xrange(2, zs[0], 2):
        if c >= 2:
            o[i] = 1
            c-=2

print ''.join(map(str,o))
