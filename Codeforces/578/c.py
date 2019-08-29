from fractions import Fraction
n, m, q = [int(x) for x in input().split()]

f = Fraction(n, m)
g = Fraction(f.numerator, n)

def bounds(t, div):
    a,b = t
    jmp = int(b*div)
    l = (a-1)//jmp
    u = l + 1
    return l, u

for _ in range(q):
    sx, sy, ex, ey = [int(x) for x in input().split()]
    a = (sy, n) if sx == 1 else (sy, m)
    b = (ey, n) if ex == 1 else (ey, m)
    la, ua = bounds(a, g)
    lb, ub = bounds(b, g)
    if la == lb and ua == ub:
        print("YES")
    else:
        print("NO")
