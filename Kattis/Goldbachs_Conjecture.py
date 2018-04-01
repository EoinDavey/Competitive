MX_N = 32002
sieve = [False]*MX_N
primes = set()
pl = []
for i in xrange(2,MX_N):
    if not sieve[i]:
        for j in xrange(i*i,MX_N,i):
            sieve[j]=True
        primes.add(i)
        pl.append(i)

for _ in xrange(input()):
    rep = set()
    x = input()
    for p in pl:
        if p >= x:
            break
        if x-p in primes:
            rep.add((min(p,x-p),max(p,x-p)))
    print "%d has %d representation(s)" % (x,len(rep))
    for p in sorted(list(rep)):
        print "%d+%d" % p
    print
