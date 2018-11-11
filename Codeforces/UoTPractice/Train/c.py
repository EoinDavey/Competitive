T = input()
for _ in xrange(T):
    n = input()
    n1 = n-1
    cnt = 0
    while n or n1:
        if n%2 != n1%2:
            cnt+=1
        n/=2
        n1/=2
    print cnt
