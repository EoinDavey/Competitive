import sys
from itertools import product
from collections import defaultdict, deque
board = [line[:-1] for line in sys.stdin]
H = len(board)
W = max(map(len, board))
nboard = defaultdict(lambda: ' ')
for x in range(len(board)):
    for y in range(len(board[x])):
        nboard[x,y] = board[x][y]
board = nboard
mvs = [(0,1),(1,0),(-1,0),(0,-1)]

lbls = defaultdict(list)
for x in range(H):
    for y in range(W):
        if not 'A' <= board[x,y] <= 'Z':
            continue
        pts = []
        if 'A' <= board[x-1,y] <= 'Z':
            pts = [(x-1,y), (x,y)]
        if 'A' <= board[x,y-1] <= 'Z':
            pts = [(x, y-1), (x,y)]
        lbl = ''.join(map(lambda x: board[x], pts))
        for o in pts:
            for mv in mvs:
                pt = o[0]+mv[0], o[1]+mv[1]
                if board[pt] == '.':
                    lbls[lbl].append(pt)

mxx = max([x for (x,y) in product(range(H),range(W)) if board[x,y] in ['#','.']])
mnx = min([x for (x,y) in product(range(H),range(W)) if board[x,y] in ['#','.']])
mxy = max([y for (x,y) in product(range(H),range(W)) if board[x,y] in ['#','.']])
mny = min([y for (x,y) in product(range(H),range(W)) if board[x,y] in ['#','.']])
def solve(recurse):
    adjList = defaultdict(list)
    for lbl, pts in lbls.items():
        if len(pts) < 2:
            continue
        a, b = pts
        if not(a[0] == mnx or a[0] == mxx or a[1] == mny or a[1] == mxy):
            a, b = b, a
        adjList[b].append((1 if recurse else 0, a[0], a[1]))
        adjList[a].append((-1 if recurse else 0, b[0], b[1]))

    for pt in product(range(H), range(W)):
        if board[pt] != '.':
            continue
        for mv in mvs:
            npt = pt[0]+mv[0], pt[1]+mv[1]
            if board[npt] == '.':
                adjList[pt].append((0, npt[0], npt[1]))

    S = lbls['AA'][0]
    S = (0, S[0], S[1])
    T = lbls['ZZ'][0]
    T = (0, T[0], T[1])
    q = deque([S])
    dist = {}
    dist[S] = 0
    while q:
        u = q.popleft()
        if u == T:
            break
        du, ux, uy = u
        for (d, vx, vy) in adjList[ux,uy]:
            if du + d < 0:
                continue
            v = (du + d, vx, vy)
            if v in dist:
                continue
            dist[v] = dist[u] + 1
            q.append(v)
    return dist[T]
print('Part A', solve(False))
print('Part B', solve(True))
