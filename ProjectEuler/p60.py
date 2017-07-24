import math
N = 10000
sieve = [False]*N
primes = []

for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j] = True
print "Sieve Generated"

prime_map = {}
def prime(x):
    if x > 300000000:
        return False
    if x in prime_map:
        return prime_map[x]
    if x < N:
        return not sieve[x]
    for y in range(2,int(math.sqrt(x))+2):
        if x%y == 0:
            prime_map[x]=False
            return False
    prime_map[x]=True
    return True

def check(p):
    for i in p:
        for j in p:
            if i==j:
                continue
            g = int(str(i) + str(j))
            if not prime(g):
                return False
    return True

for i,a in enumerate(primes):
    for j,b in enumerate(primes[i+1:],i+1):
        if not check([a,b]):
            continue
        for k,c in enumerate(primes[j+1:],j+1):
            if not check([a,b,c]):
                continue
            for l,d in enumerate(primes[k+1:],k+1):
                if not check([a,b,c,d]):
                    continue
                for m,e in enumerate(primes[l+1:],l+1):
                    if not check([a,b,c,d,e]):
                        continue
                    print [a,b,c,d,e]
