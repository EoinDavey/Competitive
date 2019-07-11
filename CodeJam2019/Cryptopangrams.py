def gcd(a,b):
    while b != 0:
        a, b = b, a % b
    return a

def dfs((a,b)):
    if (a,b) in grph:
        return b + dfs(grph[(a,b)])
    return b

for t in xrange(input()):
    n, l = map(int, raw_input().split())
    ls = map(int, raw_input().split())
    zs = zip(ls, ls[1:])
    s = set()
    for (a, b) in zs:
        g = gcd(a,b)
        if g==a or g==b or g==1:
            continue
        s.add(g)
        s.add(a/g)
        s.add(b/g)
    s = sorted(list(s))
    assert(len(s)==26)
    mp = {}
    for i in xrange(26):
        mp[s[i]] = chr(i + ord('A'))

    grph = {}
    for i in xrange(len(ls)):
        x = ls[i]
        for p in s:
            if x%p == 0:
                grph[(i,mp[p])] = (i+1, mp[x/p])

    x = ls[0]
    for p in s:
        if x%p == 0:
            s = dfs((0,mp[p]))
            if len(s) == l + 1:
                print "Case #%d:" % (t+1), s
