N = 1000000
sieve = [False]*N
primes = []
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j] = True

def count(x):
    n = len(str(x))
    ls = list(str(x))
    mx = 0
    stans = 0
    for st in range(1,2**n):
        cnt = 0
        for i in range(10):
            nls = ls[:]
            for j in range(n):
                if st&(1<<j) != 0:
                    nls[j] = chr(i+ord('0'))
            v = int("".join(nls))
            if not sieve[v] and len(str(v))==n:
                cnt+=1
        if cnt > mx:
            mx = cnt
            stans = st
    return (mx,stans)

a = 0
stout=0
for p in primes:
    (c,st) = count(p)
    if c==8:
        a = p
        stout=st
        break

n = len(str(a))
ls = list(str(a))

for i in range(10):
    nls = ls[:]
    for j in range(n):
        if stout&(1<<j) != 0:
            nls[j] = chr(i+ord('0'))
    v = int("".join(nls))
    if not sieve[v] and len(str(v))==n:
        print v
