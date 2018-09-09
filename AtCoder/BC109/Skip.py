def gcd(a,b):
    while b != 0:
        a, b = b, a % b
    return a

N, X = map(int, raw_input().split())
xs = map(int, raw_input().split())
gc = map(lambda x: abs(x - X), xs)
print reduce(gcd, gc)
