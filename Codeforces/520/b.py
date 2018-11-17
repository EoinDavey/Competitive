MX_N = 10**6+3
comp = [False]*MX_N
primes = []
for i in xrange(2, MX_N):
    if not comp[i]:
        for j in xrange(2*i, MX_N, i):
            comp[j] = True
        primes.append(i)

def solve(x):
    if x <= 2:
        return x,0
    ans = 1
    for p in primes:
        if x%p==0:
            ans*=p
    cnt = 0
    oans = ans
    while ans < x:
        ans*=ans
        cnt+=1
    if ans != x:
        cnt+=1
    return oans, cnt

x,y = solve(input())
print x,y
