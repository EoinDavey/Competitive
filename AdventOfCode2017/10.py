l = range(256)
c = 0
skp = 0
lens = map(ord, list(raw_input()))
lens += [17, 31, 73, 47, 23]

def toC(x):
    if x<=9:
        return str(x)
    return chr(x-10 + ord('a'))

def hx(x):
    hi = x/16
    lo = x%16
    o = toC(hi) + toC(lo)
    return o

for _ in xrange(64):
    for ln in lens:
        if ln >= 256:
            continue
        r = l[c: c+ln]
        if c+ln >= 256:
            r += l[:(c+ln)%256]
            assert(len(r)==ln)
        r.reverse()
        for i in xrange(len(r)):
            l[(c+i)%256] = r[i]
        c = (c + ln + skp)%256
        skp+=1

dhash = [reduce(lambda x,y:x^y, l[i:i+16]) for i in xrange(0,256,16)]
print dhash
ans = ''.join(map(hx,dhash))
print ans
print len(ans)
