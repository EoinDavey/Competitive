def cross(a, b):
    return a[0]* b[1] - a[1] * b[0];

def area(p):
    sm = 0
    for i in range(len(p)):
        sm += cross(p[i], p[(i+1)%len(p)])
    return abs(sm)

def parse(s):
    s = ''.join(s.split('.'))
    while len(s) < 16:
        s += '0'
    return int(s)

N = int(input())
p = []
for _ in range(N):
    x, y = map(parse, input().split())
    p.append((x,y))
p.append(p[0])

b = area(p)

A = 10**30

ans = 0
for x in range(1001):
    if 2*x*A <= b*1000:
        ans = x/1000.0
    else:
        break
print(ans)
