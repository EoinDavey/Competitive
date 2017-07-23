import sys

def tri():
    n = 1
    while(1):
        yield(n*(n+1)/2)
        n+=1

def pent():
    n = 1
    while(1):
        yield(n*(3*n-1)/2)
        n+=1

def hex():
    n = 1
    while(1):
        yield(n*(2*n-1))
        n+=1

t = tri()
p = pent()
h = hex()

tset = set()
pset = set()
hset = set()

l = [(t,tset),(p,pset),(h,hset)]
sets = [tset,pset,hset]

while(True):
    for (x,xset) in l:
        n = next(x)
        xset.add(n)
        if all(map(lambda x: n in x,sets)):
            if n > 40755:
                print n
                sys.exit()
