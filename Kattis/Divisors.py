import sys
N = 433
sieve = [False]*N
primes= []
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

nPrimes = len(primes)

primeFacs = [[] for _ in range(N)]
primeFacs[0]=[0 for _ in range(nPrimes)]
primeFacs[1]=[0 for _ in range(nPrimes)]

for i in range(2,N):
    t = i
    facs = [0]*nPrimes
    for j in range(nPrimes):
        while i % primes[j] == 0:
            i/=primes[j]
            facs[j]+=1
    primeFacs[t] = facs

for line in sys.stdin:
    [n,k] = map(int, line.split())

    val = [0]*nPrimes

    for x in range(n-k+1,n+1)[::-1]:
        for i in range(nPrimes):
            val[i]+=primeFacs[x][i]

    for x in range(1,k+1):
        for i in range(nPrimes):
            val[i]-=primeFacs[x][i]

    out = 1
    for i in range(nPrimes):
        out*=(val[i]+1)

    print out
