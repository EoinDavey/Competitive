for _ in xrange(input()):
    P,R,F = map(int,raw_input().split())
    t = 0
    while 1:
        if P > F:
            print t
            break
        P = P*R
        t+=1
