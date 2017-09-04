while(True):
    n = int(raw_input())
    if n==-1:
        break
    prev = 0
    out = 0
    for _ in range(n):
        [a,b] = map(int,raw_input().split())
        out += a * (b-prev)
        prev = b
    print "%d miles" % out

