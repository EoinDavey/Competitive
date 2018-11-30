def toT(h, m):
    return h*60 + m

def fromT(t):
    h = t/60
    m = t%60
    return ("%d:%d" % (h,m) if m > 9 else "%d:0%d" % (h,m))

tm = [0,0]
scr = [0,0]
pT = 0
evs = [raw_input().split() for _ in xrange(input())]
evs.append(["H", "1", "32:00"])
for s in evs:
    pts = int(s[1])
    tms = map(int, s[2].split(':'))
    t = apply(toT, tms)
    if scr[0] > scr[1]:
        tm[0] += t-pT
    elif scr[1] > scr[0]:
        tm[1] += t-pT
    pT = t
    if s[0]=='H':
        scr[0]+=pts
    else:
        scr[1]+=pts

print ("H" if scr[0] > scr[1] else "A"), fromT(tm[0]), fromT(tm[1])
