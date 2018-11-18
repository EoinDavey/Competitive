def gcd(a,b):
    while b:
        a,b = b, a%b
    return a
for _ in xrange(input()):
    print ['No', 'Yes'][(lambda x: x[2]%gcd(x[0],x[1]) == 0)(map(int, raw_input().split()))]
