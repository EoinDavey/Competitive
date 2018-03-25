import operator as op

p = 1000*1000*1000+7
memo = {}

def fermat_binom(n,k):
    k = min(k,n-k)
    if k < 0:
        return 0
    num =1
    for i in xrange(n,n-k,-1):
        num = (num*i)%p
    denom = 1
    for i in xrange(1,k+1):
        denom = (denom*i)%p
    return (num*pow(denom,p-2,p))%p

def nways((a,b),(c,d)):
    if ((a,b),(c,d)) in memo:
        return memo[((a,b),(c,d))]
    dx = c-a
    dy = d-b
    x = fermat_binom(dx+dy,dx)
    memo[((a,b),(c,d))] = x
    return x

def npath(xs):
    return reduce(lambda (y,q),x:((y*nways(q,x)%p),x),xs,(1,(1,1)))[0]

def rec(st,pth):
    c = 0
    for i in xrange(n):
        if (st&(1<<i))==0:
            c = (c-rec(st|(1<<i),pth+[pts[i]]))%p
    return (c + (npath(pth+[(w,h)]) if st != 0 else 0))%p

w,h = map(int,raw_input().split())
n = input()

pts = [tuple(map(int,raw_input().split())) for _ in range(n)]

ways = rec(0,[])

print((p-ways)%p)
