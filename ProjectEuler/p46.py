N = 10000

primes = []
sieve = [False]*N

s = set()

for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j] = True

squares = [i**2 for i in range(1001)]

for i in primes:
    for j in squares:
        s.add(i + 2*j)

n = 1
while(n in s or not sieve[n]):
    n+=2
print n
