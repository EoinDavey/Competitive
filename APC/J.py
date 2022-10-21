from math import pi, sin, cos, tan, sqrt
n, e = [int(x) for x in input().split()]
rs = [int(x) for x in input().split()]

def fits(r, num):
    if num == 1:
        return True
    ang = 2*pi / num
    p1 = (r, 0)
    p2 = (r * cos(ang), r * sin(ang))
    d = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)
    return d >= e**2

p = 0
for r in rs:
    L, R = 1, 10**9
    while L < R:
        md = (L+R+1) // 2
        if fits(r, md) or fits(r-1e-6, md) or fits(r+1e-7, md):
            L = md
        else:
            R = md - 1
    assert(L < 10**6)
    #print(r, L)
    p += L

print(p)
#print(fits(2, 6))
