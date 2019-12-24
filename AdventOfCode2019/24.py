import sys
from itertools import product
from collections import defaultdict
board = [line.strip() for line in sys.stdin]
H = len(board)
W = len(board[0])
nboard = defaultdict(lambda: '.')
nboard.update({(x,y):board[x][y] for (x,y) in product(range(H),range(W))})
board = nboard 

mvs = [(0,1), (0, -1), (1, 0), (-1, 0)]

def nextGen(b):
    nb = defaultdict(lambda: '.')
    for pt in product(range(H), range(W)):
        cnt = 0
        for mv in mvs:
            npt = pt[0]+mv[0], pt[1]+mv[1]
            if b[npt] == '#':
                cnt += 1
        if b[pt] == '#':
            nb[pt] = '#' if cnt == 1 else '.'
        else:
            nb[pt] = '#' if 1 <= cnt <= 2 else '.'
    return nb

def toKey(b):
    sm = 0
    for (x, y) in product(range(H), range(W)):
        if b[x,y] == '#':
            sm += 2**(x*W + y)
    return sm

def part1(b):
    s = set([toKey(b)])
    while True:
        b = nextGen(b)
        k = toKey(b)
        if k in s:
            return k
        s.add(k)

def nextGen2(st, adjList):
    cnt = defaultdict(int)
    for (d, x, y) in st:
        for (dd, nx, ny) in adjList[x,y]:
            cnt[(d + dd, nx, ny)] += 1
    nst = set()
    for pt in st:
        if cnt[pt] == 1:
            nst.add(pt)
    for k, v in cnt.items():
        if 1 <= v <= 2 and k not in st:
            nst.add(k)
    return nst

def part2(b):
    adjList = defaultdict(list)
    for (x, y) in product(range(H), range(W)):
        if (x,y) == (2,2):
            continue
        for mv in mvs:
            nx, ny = x + mv[0], y + mv[1]
            if not(0 <= nx < 5 and 0 <= ny < 5) or (nx, ny) == (2,2):
                continue
            adjList[(x,y)].append((0, nx, ny))
    for x in range(H):
        adjList[(x, 0)].append((1, 2, 1))
        adjList[(2, 1)].append((-1, x, 0))
        adjList[(x, 4)].append((1, 2, 3))
        adjList[(2, 3)].append((-1, x, 4))
    for x in range(H):
        adjList[(0, x)].append((1, 1, 2))
        adjList[(1, 2)].append((-1, 0, x))
        adjList[(4, x)].append((1, 3, 2))
        adjList[(3, 2)].append((-1, 4, x))

    st = set()
    for (x, y) in product(range(H), range(W)):
        if b[x,y] == '#':
            st.add((0, x, y))

    for _ in range(200):
        st = nextGen2(st, adjList)
    return len(st)

print(part1(board))
print(part2(board))
