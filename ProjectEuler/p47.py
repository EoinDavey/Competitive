N = 1000000

sieve = [False]*N
primes = []

for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j] = True

def pfcount(n):
    t = n
    cnt = 0
    if not sieve[n]:
        return 1
    for p in primes:
        if t==1:
            break
        if t%p==0:
            cnt+=1
            while(t%p==0):
                t/=p
    return cnt

target = 4

n = 1
run = 0
while(True):
    if pfcount(n) == target:
        run+=1
    else:
        run = 0
    if run == target:
        print (n-target+1)
        break
    n+=1
