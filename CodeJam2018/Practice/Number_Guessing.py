import sys
T = input()
for _ in xrange(T):
    A, B = map(int,raw_input().split())
    A+=1
    N = input()
    while 1:
        md = (A+B)/2
        print md
        sys.stdout.flush()
        resp = raw_input()
        if resp=="TOO_SMALL":
            A = md+1
        elif resp=="TOO_BIG":
            B = md-1
        elif resp=="CORRECT":
            break
        else:
            sys.exit(0)
