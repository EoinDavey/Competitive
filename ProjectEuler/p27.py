def p(a,b):
    n = 0
    while(True):
        c = n**2 + a*n + b
        if c < 0 or c > N or sieve[c]:
            break
        n+=1
    return n

N = 1000000
sieve = [False]*N
primes = []


for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True

mx = 0
for a in range(-1000,1001):
    for b in primes[:169]:
        c = p(a,b)
        if c > mx:
            mx = c
            print mx, a*b
