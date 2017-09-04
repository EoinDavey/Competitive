N = int(raw_input())
for _ in xrange(N):
    x = int(raw_input())
    if x%2==0:
        print "%d is even" % x
    else:
        print "%d is odd" % x
