import math
import itertools
def fac(i):
    if i <= 1:
        return 1
    return i * fac(i-1)

def prime(p):
    for i in range(2,int(math.sqrt(p))+2):
        if p%i==0:
            return False
    return True

l = ['1','2','3','4','5','6','7','8','9']


mx = 0
for n in range(1,8):
    f = fac(n)
    p = itertools.permutations(l[:n])
    cnt = 0
    for m in range(f):
        perm = next(p)
        x = int("".join(list(perm)))
        if prime(x):
            cnt+=1
            mx = max(mx,x)
print mx
