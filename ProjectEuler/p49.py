N = 10000
sieve = [False]*N
primes=[]
for i in range(2,N):
    if not sieve[i]:
        primes.append(i)
        for j in range(2*i,N,i):
            sieve[j]=True
def st(x):
    l = list(str(x))
    l.sort()
    return l

def check(i,j):
    ns = [i + x*j for x in range(3)]
    if not all(map(lambda x: x < 10000 and not sieve[x],ns)):
        return False
    sted = map(lambda x: st(x),ns)
    return all(map(lambda x: x==sted[0],sted))

for a in range(1000,10000):
    for j in range(1, (10000-a)/2):
        if check(a,j):
            print [a + x*j for x in range(3)]
