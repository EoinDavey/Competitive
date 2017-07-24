import math
tenth = (1,10)

def prime(x):
    for y in range(2,int(math.sqrt(x))+2):
        if x%y==0:
            return False
    return True

def less((x1,y1),(x2,y2)):
    return x1*y2 < y1*x2

def gcd(a,b):
    while b!=0:
        a,b = b,a%b
    return a

def red((t,b)):
    g = gcd(t,b)
    return (t/g,b/g)

n = 2
l = 0
pcount = 0
tot = 1
while(True):
    l+=1
    sz = 2*l
    for t in range(4):
        if t==0:
            n+=sz-1
        else:
            n+=sz
        if prime(n):
            pcount+=1
    tot+=4
    n+=1
    f = (pcount,tot)
    if less(red(f),tenth):
        print "Ans",sz+1
        break
print l
