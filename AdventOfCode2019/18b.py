import sys
from itertools import product
from collections import deque, defaultdict
board = [line.strip() for line in sys.stdin]
H = len(board)
W = len(board[0])
board = {(x,y) : board[x][y] for x in range(H) for y in range(W)}
mvs = [(1,0), (-1,0), (0, 1), (0, -1)]
def inBoard(x,y): return 0<=x<H and 0<=y<W

ogo = [pt for pt in product(range(H), range(W)) if board[pt] == '@'][0]
newCenter=[
        '@#@',
        '###',
        '@#@'
]
for i in range(3):
    for j in range(3):
        board[ogo[0] + i - 1, ogo[1] + j - 1] = newCenter[i][j]

keypts = [(x,y) for x in range(H) for y in range(W) if 'a' <= board[x, y] <= 'z']
keyPtInd = {(x,y):i for ((x,y), i) in zip(keypts, range(len(keypts)))}
assert(len(keypts) == len(keyPtInd))

doors = [(x,y) for x in range(H) for y in range(W) if 'A' <= board[x, y] <= 'Z']
doorInd = {(x,y):i for ((x,y), i) in zip(doors, range(len(doors)))}
assert(len(doors) == len(doorInd))

keyPt2Dr = {}
for k in range(len(keypts)):
    tgt = chr(ord(board[keypts[k]]) - ord('a') + ord('A'))
    dr = [x for x in range(len(doors)) if board[doors[x]] == tgt]
    if dr:
        keyPt2Dr[k] = dr[0]

def getDists(pos):
    q = deque([pos])
    d = defaultdict(lambda: 10**100)
    d[pos] = 0
    kds = {}
    while q:
        u = q.popleft()
        for mv in mvs:
            v = u[0] + mv[0], u[1] + mv[1]
            if 'A' <= board[v] <= 'Z' or board[v] == '#' or v in d:
                continue
            d[v] = d[u] + 1
            if 'a' <= board[v] <= 'z':
                kds[keyPtInd[v]] = d[v]
            q.append(v)
    return kds

vis = 0
allkeys = 2**len(keypts) - 1
memo = {}
def srch(bots):
    global memo, vis
    '''
    print(bots)
    for x in range(H):
        rw = ""
        for y in range(W):
            rw += board[x,y]
        print(rw)
    '''
    key = (tuple(bots), vis)
    if key in memo:
        return memo[key]
    if(vis == allkeys):
        memo[key] = 0
        return 0

    mn = 10000000
    for b in range(len(bots)):
        dists = getDists(bots[b])

        for i in range(len(keypts)):
            if (vis&(1<<i))!=0 or i not in dists:
                continue
            if i in keyPt2Dr:
                door = doors[keyPt2Dr[i]]
                old = board[door]
                oldpos = bots[b]
                board[door] = '.'
                vis |= (1<<i)
                bots[b] = keypts[i]
                sub = srch(bots)
                bots[b] = oldpos
                vis ^= (1<<i)
                board[door] = old
                mn = min(mn, dists[i] + sub)
            else:
                oldpos = bots[b]
                vis |= (1<<i)
                bots[b] = keypts[i]
                sub = srch(bots)
                bots[b] = oldpos
                vis ^= (1<<i)
                mn = min(mn, dists[i] + sub)

    memo[key] = mn
    return mn

print(srch([pt for pt in product(range(H), range(W)) if board[pt] == '@']))
