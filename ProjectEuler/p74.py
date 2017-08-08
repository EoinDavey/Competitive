def fac(x):
    if x<=1:
        return 1
    return x*fac(x-1)

facs = [fac(i) for i in range(10)]

def facSum(x):
    c = 0
    while(x>0):
        c+=facs[x%10]
        x/=10
    return c


def ngen(x):
    yield x
    while(1):
        x = facSum(x)
        yield(x)

def floyds(x):
    tgen = ngen(x)
    hgen = ngen(x)
    t = next(tgen)
    h = next(hgen)
    t = next(tgen)
    h = next(hgen)
    h = next(hgen)
    while t!=h:
        t = next(tgen)
        h = next(hgen)
        h = next(hgen)
    tgen = ngen(x)
    t = next(tgen)
    c = 0
    while t!=h:
        t=next(tgen)
        h=next(hgen)
        c+=1
    l=1
    t=next(tgen)
    while t!=h:
        t=next(tgen)
        l+=1
    return l+c

cnt = 0
for i in range(2,1000000):
    if i%10000==0:
        print i
    if floyds(i)==60:
        cnt+=1
print cnt
