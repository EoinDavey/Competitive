import itertools

primes = [2,3,5,7,11,13,17]

def fac(i):
    return 1 if i <= 0 else i*fac(i-1)

def check(p):
    for x,prime in enumerate(primes):
        _p = p[x+1:x+4]
        if int(_p) % prime != 0:
            return False
    return True

l = "0123456789"
n = fac(10)
perm = itertools.permutations(l)
s = 0
for _ in range(n):
    p = "".join(list(next(perm)))
    if check(p):
        s+=int(p)
print s
