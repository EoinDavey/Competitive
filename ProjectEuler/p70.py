N = 1000000
sieve = [False]*N
primes=[]
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

def calc(x):
    if not sieve[x]:
        return x-1
    t = x
    total = 1
    for p in primes:
        cnt = 0
        while(t%p==0):
            t/=p
            cnt+=1
        if cnt > 0:
            total*=p**cnt - p**(cnt-1)
        if t==1:
            break
    return total

dp = [0]*N
for p in primes:
    dp[p]=p-1
