import math
n, k = *map(int, input().split()),
pts = [[float(x) for x in input().split()] for _ in range(n)]

pts.sort(key=lambda p: math.sqrt(p[0]**2 + p[1]**2 + p[2]**2))

print(math.sqrt(pts[k-1][0]**2 + pts[k-1][1]**2 + pts[k-1][2]**2))
