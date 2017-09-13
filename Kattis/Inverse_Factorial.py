import math
N = raw_input()

if len(N) <= 6:
    N = int(N)
    for i in xrange(2,300000):
        if N==1:
            print i-1
            break
        N/=i
else:
    N = len(N)
    o = 0.0
    for i in xrange(1,300000):
        o+=math.log10(i)
        if 1 + int(math.floor(o)) == N:
            print i
            break
