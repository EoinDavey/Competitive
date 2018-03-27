mxn = 10010
sieve = [False]*mxn
sieve[0]=sieve[1]=True
for i in xrange(2,mxn):
    if not sieve[i]:
        for j in xrange(i*i,mxn,i):
            sieve[j]=True

def isHappy(m):
    seen = set()
    seen.add(m)
    while 1:
        m = str(sum(map(lambda x: (ord(x)-ord('0'))**2,m)))
        if m=="1":
            return True
        if m in seen:
            return False
        seen.add(m)

for _ in xrange(input()):
    k,m = map(int,raw_input().split())
    #isHappy(str(m))
    print k,m, ["NO","YES"][(not sieve[m]) and isHappy(str(m))]
