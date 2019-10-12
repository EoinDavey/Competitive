import sys
infile = sys.stdin
def inp(): return infile.readline().strip()
for _ in range(int(inp())):
    n, k = *map(int, inp().split()),
    a = *map(int, inp().split()),
    if sum(a) % 2 != k % 2:
        print("NO")
        continue
    r = 0
    sm = 0
    o = []
    while r < n:
        while r < n and sm % 2 == 0:
            sm += a[r]
            r += 1
        o.append(r)
        sm = 0
    if len(o) < k:
        print("NO")
        continue
    sys.stdout.write("YES\n")
    sys.stdout.write(' '.join(map(str,o[:k-1]+[n])))
    sys.stdout.write('\n')
