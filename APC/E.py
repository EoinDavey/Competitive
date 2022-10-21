n = int(input())

shps = set()
for _ in range(n):
    m = int(input())
    pts = []
    for _ in range(m):
        x, y = [int(x) for x in input().split()]
        pts.append((x, y))
    pts = sorted(pts)
    fst = pts[0]
    pts = [(x - fst[0], y - fst[1]) for (x, y) in pts]
    shps.add(tuple(pts))

print(len(shps))
