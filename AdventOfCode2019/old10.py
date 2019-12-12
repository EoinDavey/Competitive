import sys
from collections import defaultdict
from math import gcd, atan2

board = list(map(lambda x: x.strip(), sys.stdin))
H = len(board)
W = len(board[0])


def a():
    mx = 0
    ax = 0
    ay = 0
    for x in range(H):
        for y in range(W):
            if board[x][y] != "#":
                continue
            s = set()
            for a in range(H):
                for b in range(W):
                    if board[a][b] != "#" or a == x and b == y:
                        continue
                    g = gcd(a - x, b - y)
                    s.add(((a - x) / g, (b - y) / g))
            if len(s) > mx:
                mx = len(s)
                ax = x
                ay = y
    return mx, ax, ay


def b(ax, ay):
    pts = defaultdict(list)
    for a in range(H):
        for b in range(W):
            if board[a][b] != "#" or a == ax and b == ay:
                continue
            g = gcd(a - ax, b - ay)
            pts[((a - ax) / g, (b - ay) / g)].append((a, b))
    keys = list(pts.keys())
    keys.sort(key=lambda x: atan2(-x[1], x[0]))
    for k in keys:
        pts[k].sort(key=lambda x: -(abs(x[0] - ax) + abs(x[1] - ay)))
    cnt = 0
    ki = 0
    while True:
        if len(pts[keys[ki]]) == 0:
            ki = (ki + 1) % len(keys)
            continue
        pt = pts[keys[ki]].pop()
        cnt += 1
        if cnt == 200:
            return pt[1] * 100 + pt[0]
        ki = (ki + 1) % len(keys)


amx, ax, ay = a()
print("Part A", amx)
print("Part B", b(ax, ay))
