mnthMp = [0, 31,28,31,30,31,30,31,31,30,31,30,31]
sm = [0]*len(mnthMp)
for i in xrange(1, len(sm)):
    sm[i] = mnthMp[i] + sm[i-1]

assert(len(mnthMp) == 13)
assert(sum(mnthMp) == 365)

def toD(d, m):
    return d + sm[m-1] - 1

def iD(c):
    for m in xrange(1, 13):
        for d in xrange(1, mnthMp[m]+1):
            if toD(d,m)==c:
                return m, d

kD = toD(27, 10)

n = input()
days = [False]*365

for _ in xrange(n):
    m, d = map(int, raw_input().split()[1].split('-'))
    days[toD(d,m)]  = True

rn = 0
rnv = [0]*365
mxRn = 0
wn = 0
for d in xrange(365*2):
    if not days[d%365]:
        rn+=1
    else:
        rn = 0
    rnv[d%365] = max(rnv[d%365], rn)

for d in xrange(365):
    if rnv[(d+kD+1)%365] > mxRn:
        mxRn = rnv[(d+kD+1)%365]
        wn = (d+kD+1)%365

m, d = iD(wn)
pad = lambda x: '0' + str(x) if x <= 9 else str(x)
print "%s-%s" % (pad(m), pad(d))
