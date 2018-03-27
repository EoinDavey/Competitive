def gcd(a,b):
    while b!=0:
        a,b = b,a%b
    return a

def red((a,b)):
    g = gcd(a,b)
    return (a/g,b/g)

def add((a,b),(c,d)):
    return (a*d + c*b,b*d)

def mul((a,b),(c,d)):
    return (a*c,b*d)

def conv(x):
    return mul(add(x,(-32,1)),(5,9))

a,b = map(int,raw_input().split("/"))
print "%d/%d" % red(conv((a,b)))
