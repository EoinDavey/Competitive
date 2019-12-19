N, R = *map(int, input().split()),
crcs = [[float(x) for x in input().split()] for _ in range(N)]

for crc in crcs:
    x, y, r = crc
    print("(x - %.6f)^2 + (y - %.6f)^2 = %.6f^2" % (x, y, r))
