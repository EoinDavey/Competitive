import string

inp = map(int,raw_input().split(','))

def pr(xs):
    return "".join(map(chr,xs))

def gen(key):
    p = 0
    while(1):
        yield key[p]
        p=(p+1)%3

def dec(xs,k):
    g = gen(k)
    ns = [x ^ next(g) for x in xs]
    return ns

allowed = string.ascii_lowercase + string.ascii_uppercase + ' '+','+'(' + ')' + string.digits
for _a in range(26):
    a = _a + ord('a')
    for _b in range(26):
        b = _b + ord('a')
        for _c in range(26):
            c = _c + ord('a')
            key = [a,b,c]
            dc = dec(inp[:12],key)
            if all(map(lambda x: x in allowed,pr(dc))):
                print key, pr(dc)

a = [103,111,100]
print sum(dec(inp,a))
