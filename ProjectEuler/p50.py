N = 1000000
sieve = [False]*N
primes=[]
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

mx = 0
for i,p in enumerate(primes):
    s = p
    k = 1
    while(s < N):
        s+=primes[i+k]
        k+=1
        if s >= N:
            break
        if not sieve[s]:
            if k > mx:
                mx = k
                print s
