def v10(x):
    n = len(str(x))-1
    nn = 0 if n <= 0 else (45 * n * (10**(n-1)))
    x = int(str(x)[0])
    sm = 0
    for i in range(x):
        sm+= i*(10**n) + nn
    sm += x
    return sm

def gdsum(x):
    sm = 0
    n = len(str(x))
    for c in range(1,n+1):
        v = x%(10**c)
        x -= v
        sm+= int(str(x)[0]) * v
        sm += v10(v)
    return sm


t = int(raw_input())
for _ in range(t):
    [a,b] = map(int,raw_input().split())
    res = gdsum(b) - (0 if a <= 1 else gdsum(a-1))
    print int(res)
