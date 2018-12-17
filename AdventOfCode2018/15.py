import sys
import time
import itertools
from collections import deque, defaultdict

ogboard = [list(line.strip()) for line in sys.stdin]

mvs = [(-1,0), (0, -1), (0, 1), (1, 0)]

def valid(x,y):
    return x and y and x < len(board) and y < len(board[0])

def adj(x,y,tgt):
    for dx, dy in mvs:
        ni = x + dx
        nj = y + dy
        if valid(ni, nj) and board[ni][nj] == tgt:
            return True
    return False

chrs = {
        '.' : ' ',
        '#' : '#',
        'G' : u'\u001b[31mG\u001b[0m',
        'E' : u'\u001b[32mE\u001b[0m',
}
def prB():
    print u'\u001b[2J'
    for b in board:
        print ''.join(map(lambda x: chrs[x], b))

def findEn(x,y,tgt):
    assert(board[x][y] in ["E", 'G'])
    o = (10**18, 10**18, 10**18)
    if adj(x,y,tgt):
        return o 

    vis = set()

    cls = (10**18, 10**18, 10**18)

    q = deque()
    q.append((0, x, y))

    while q:
        d, i, j = q.popleft()
        for dx, dy in mvs:
            ni = i + dx
            nj = j + dy
            if valid(ni, nj) and board[ni][nj] == '.' and (ni,nj) not in vis:
                q.append((d+1, ni, nj))
                vis.add((ni,nj))
            if board[i][j]=='.'  and valid(ni, nj) and board[ni][nj] == tgt:
                cls = min(cls, (d, i, j))

    if cls[0] > 1000:
        return o

    q = deque()
    vis = set()
    q.append((0, cls[1], cls[2]))
    vis.add((cls[1], cls[2]))

    while q:
        d, i, j = q.popleft()
        if board[i][j]=='.' and abs(i-x) + abs(j-y) == 1:
            o = min(o, (d, i, j))
        for dx, dy in mvs:
            ni = i + dx
            nj = j + dy
            if valid(ni, nj) and board[ni][nj] == '.' and (ni,nj) not in vis:
                q.append((d+1, ni, nj))
                vis.add((ni,nj))
    return o

def solve(eat=3, pr=False):
    global board,hp,cnt,pos,dead

    board = [b[:] for b in ogboard]
    hp = [[0]*len(board[0]) for _ in xrange(len(board))]

    pos = []
    dead = []
    cnt = defaultdict(int)

    for i in xrange(len(board)):
        for j in xrange(len(board[0])):
            if board[i][j] in ["E","G"]:
                pos.append((i,j))
                hp[i][j] = 200
                dead.append(False)
                cnt[board[i][j]] += 1

    if pr:
        prB()

    turns = 0
    while True:
        order = sorted(range(len(pos)), key=lambda x: pos[x])
        for i in order:
            x, y  = pos[i]
            if dead[i]:
                continue

            assert(board[x][y] in ["E", "G"])
            assert(hp[x][y])

            tgt = 'G' if board[x][y] == 'E' else 'E'
            if cnt[tgt] == 0:

                #combat over

                if pr:
                    prB()

                hpsm = 0
                for i in xrange(len(pos)):
                    if not dead[i]:
                        hpsm += hp[pos[i][0]][pos[i][1]]
                return turns*hpsm
                

            en = findEn(x,y,tgt)
            if en[0] < 10000:
                assert(not adj(x,y,tgt))
                nx,ny = en[1], en[2]
                assert(board[nx][ny] == '.')
                board[nx][ny] = board[x][y]
                board[x][y] = '.'
                hp[nx][ny] = hp[x][y]
                pos[i] = (nx,ny)
                x, y = nx,ny

            assert(board[x][y] in ["E", "G"])


            #attack
            mn = (10**10, 0, 0)
            for dx, dy in mvs:
                nx = x+dx
                ny = y+dy
                if valid(nx, ny) and board[nx][ny] == tgt:
                    mn = min(mn, (hp[nx][ny], nx, ny))

            if mn[0] < 300:
                assert(adj(x,y,tgt))
                dx, dy = mn[1],mn[2]
                hp[dx][dy] -= eat if board[x][y]=='E' else 3
                if hp[dx][dy] <= 0:
                    cnt[board[dx][dy]] -= 1
                    board[dx][dy] = '.'
                    for k in xrange(len(pos)):
                        if not dead[k] and pos[k][0]==dx and pos[k][1] ==dy:
                            dead[k] = True
                            break
        if pr:
            prB()
            time.sleep(0.1)
        turns += 1

print solve(pr=True)

pw = 0
ecnt = len(filter(lambda (x,y): ogboard[x][y]=='E', itertools.product(xrange(len(board)), xrange(len(board[0])))))
while True:
    t = solve(pw)
    if cnt['E'] == ecnt:
        solve(eat=pw,pr=True)
        print "part 2:", t
        break
    pw+=1
