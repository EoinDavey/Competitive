def inp(): return int(input())

for _ in range(inp()):
    a, b, c = sorted(map(int,input().split()))
    p = a
    q = b
    d = min(q - p, c)
    p += d
    c -= d
    if c:
        print(p + c//2)
    else:
        print(min(p,q))
