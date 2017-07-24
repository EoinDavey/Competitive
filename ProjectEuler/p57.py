two = (2,1)
one = (1,1)
half = (1,2)

def oneover((x,y)):
    return (y,x)

def red((t,b)):
    g = gcd(t,b)
    return (t/g,b/g)

def gcd(a,b):
    while b!=0:
        a,b = b,a%b
    return a

def add((x1,y1),(x2,y2)):
    t = x1*y2 + x2*y1
    b = y1*y2
    return (t,b)

def check((t,b)):
    return len(str(t)) > len(str(b))

cnt = 0
for n in range(1000):
    t = half
    for x in range(n):
        t = oneover(add(two,t))
    t = red(add(one,t))
    if check(t):
        cnt+=1
print cnt
