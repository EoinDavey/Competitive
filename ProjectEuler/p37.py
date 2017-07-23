N = 1000000
sieve = [False]*N
primes = []

def check(p):
    ps = str(p)
    n = len(ps)
    return all([not sieve[int(ps[i:])] and not sieve[int(ps[:n-i])] for i in range(n)])

sieve[1]=sieve[0]=True
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j] = True

s=0
for p in primes[4:]:
    if check(p):
        s+=p
print s
