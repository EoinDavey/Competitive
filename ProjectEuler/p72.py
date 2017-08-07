N=1000001
sieve=[False]*N
sieve[0]=True
sieve[1]=True
primes = []
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

memo = [i for i in range(N)]

for i in range(1,N):
    if not sieve[i]:
        for j in range(i,N,i):
            memo[j] -= memo[j]/i

sm=0
for i in range(N):
    sm+=memo[i]
print sm-1
