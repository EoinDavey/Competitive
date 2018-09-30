for _ in xrange(input()):
    N = input()
    p = 11**N
    ntwos = 0
    while len(str(p)) > N:
        p /= 11
        p*=2
        ntwos+=1
    out = []
    for i in xrange(ntwos):
        out.append("2")
    for i in xrange(N-ntwos):
        out.append("11")
    print " ".join(out)
