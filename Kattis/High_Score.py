for _ in xrange(input()):
    xs = map(int,raw_input().split())
    abc = xs[:3]
    d = xs[3]
    if all(map(lambda x: x < 10,xs)):
        mx = 0
        a,b,c = abc
        for i in xrange(d+1):
            for j in xrange(d-i+1):
                k = d-i-j
                mx = max(mx, (a+i)**2 + (b+j)**2 + (c+k)**2 + 7*min(a+i,b+j,c+k))
        print mx
    else:
        ind = max(range(3),key=lambda x: abc[x])
        abc[ind]+=d
        a,b,c = abc
        print a**2 + b**2 + c**2 + 7*min(a,b,c)
