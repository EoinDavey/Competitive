import sys

mvs = [line.strip().split() for line in sys.stdin]

def mul2x2(x, y, N):
    a, b = x[0];c, d = x[1];e, f = y[0];g, h = y[1]
    return [
        [(a*e + b*g)%N, (a*f + b*h)%N],
        [(c*e + d*g)%N, (c*f + d*h)%N],
    ]

def matPow(x, n, N):
    base = [x[:] for x in x]
    ans = [[1,0],[0,1]]
    while n:
        if n % 2 == 1:
            ans = mul2x2(ans, base, N)
        base = mul2x2(base, base, N)
        n //= 2
    return ans

def getAB(N):
    a, b = 1, 0
    for mv in mvs:
        if mv[0] == 'cut':
            n = int(mv[1])
            a, b = a, (b - n)%N
        elif mv[1] == 'with':
            n = int(mv[3])
            a, b = (n*a)%N, (n * b)%N
        else:
            a, b = (-a)%N, (-b - 1)%N
        assert(a >= 0 and b >= 0)
    return a, b

p1a,p1b = getAB(10007)
print('Part 1', (p1a*2019 + p1b)%10007)

N = 119315717514047 
n = 101741582076661
p2a, p2b = getAB(N)
p = matPow([[p2a, p2b], [0, 1]], n, N)
A, B = p[0]
ainv = pow(A, N - 2, N)
X = ((2020 - B) * ainv) % N
print('Part 2', X)
