a,b,x,y = map(int, raw_input().split())
def gcd(a,b):
    while b:
        a, b = b, a%b
    return a

g = gcd(x,y)
x/=g
y/=g

mn = min(a/x, b/y)
print mn
