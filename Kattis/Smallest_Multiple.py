import sys
def gcd(a,b):
    while b!= 0:
        a,b = b,a%b
    return a

def lcm(a,b):
    return (a*b)/gcd(a,b)


for line in sys.stdin:
    xs = map(int,line.split())
    print reduce(lcm,xs[1:],xs[0])
