primes = []
N = 1000000
sieve = [False]*N

def check(p):
    ps = str(p)
    n = len(ps)
    return all([ not sieve[int(ps[i:] + ps[:i])] for i in range(n)])

for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

print sum([1 if check(p) else 0 for p in primes])
