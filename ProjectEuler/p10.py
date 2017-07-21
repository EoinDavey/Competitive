N = 2000000
sieve = [False]*N

s = 0
for i in range(2,N):
    if not sieve[i]:
        s+=i
        for j in range(i,N,i):
            sieve[j]=True
print s
