def cw(x):
    return [1, 0, 3, 2][x]

def ccw(x):
    return [3, 2, 1, 0][x]

def f(x,y,n):
    if n==2:
        return 0
    md = n/2
    if x==md and y==md-1 or y==md and x==md-1:
        return 0
    if x < md and y < md:
        return f(x, y, md)
    if x >= md and y >= md:
        return f(x - md, y - md, md)
    if x < md:
        return cw(f(x, n - y - 1, md))
    return ccw(f(n - x - 1, y, md))

for _ in xrange(input()):
    x, y = map(int, raw_input().split())
    print f(x, y, 2**61)
