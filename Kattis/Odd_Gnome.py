for _ in xrange(input()):
    gs = map(int,raw_input().split())[1:]
    for i in xrange(1,len(gs)-1):
        if sorted(gs[:i] + gs[i+1:]) == gs[:i]+gs[i+1:]:
            print i+1
            break
