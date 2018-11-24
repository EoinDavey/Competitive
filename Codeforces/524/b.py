def al(x):
    return (x*(x+1))/2

def nodds(x):
    return (x+1)/2

def sm(r):
    if r <= 0:
        return 0
    smodds = nodds(r)**2
    evs = r - nodds(r)
    smevs = evs*(evs+1)
    return -smodds + smevs

for _ in xrange(input()):
    l, r = map(int, raw_input().split())

    print sm(r) - sm(l-1)
