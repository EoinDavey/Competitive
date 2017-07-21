N = 10000000

sieve = [False]*N
primes = []
cnt = 0

for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        cnt+=1
        if cnt == 10001:
            break
        for j in range(i,N,i):
            sieve[j]=True

print max(primes)
