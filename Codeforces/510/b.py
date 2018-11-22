st = {}

for _ in xrange(input()):
    x = raw_input().split()
    p = int(x[0])
    s = x[1]
    o = 0
    for c in s:
        o |= 1<< (ord(c)-ord('A'))
    if o in st:
        st[o] = min(st[o], p)
    else:
        st[o] = p

mn = 10**10
for i in xrange(8):
    if i not in st:
        continue
    if  i ==7:
        mn = min(mn, st[i])
    for j in xrange(8):
        if j not in st:
            continue
        if  (i | j) ==7:
            mn = min(mn, st[i] + st[j])
        for k in xrange(8):
            if k not in st:
                continue
            if  (i | j | k)==7:
                mn = min(mn, st[i] + st[j] + st[k])
if mn >= 10**10:
    print "-1"
else:
    print mn
