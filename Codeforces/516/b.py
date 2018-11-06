n = input()
for _ in xrange(n):
    a = input()
    cnt = 0
    while a:
        if a%2==1:
            cnt+=1
        a/=2
    print 2**cnt
