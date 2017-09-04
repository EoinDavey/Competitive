T = int(raw_input())
for _ in xrange(T):
    n = int(raw_input())
    s = set()
    for _ in xrange(n):
        s.add(raw_input())
    print len(s)
