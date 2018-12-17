import sys
import time
from collections import Counter, deque, defaultdict

sys.setrecursionlimit(3000)
ls = [line.strip() for line in sys.stdin]


xlns = []
ylns = []
for l in ls:
    l = l.split()
    f = l[0].split('=')
    s = l[1].split('=')
    r = map(int, s[1].split('..'))
# swapped to my coords
    if f[0]=='y':
        ylns.append((int(f[1][:-1]), r[0],r[1]))
    else:
        xlns.append((int(f[1][:-1]), r[0],r[1]))

minX = min(map(lambda x: x[0], ylns))
minX = min(minX, min(map(lambda x: x[1], xlns)))
minX -=3

maxX = max(map(lambda x: x[0], ylns))
maxX = max(maxX, max(map(lambda x: x[1], xlns)))
maxX +=3

minY = min(map(lambda x: x[0], xlns))
minY = min(minY, min(map(lambda x: x[1], ylns)))
minY -=3

maxY = max(map(lambda x: x[0], xlns))
maxY = max(maxY, max(map(lambda x: x[1], ylns)))
maxY +=3

Xdim = maxX - minX
Ydim = maxY - minY

board = [['.']*Ydim for _ in xrange(Xdim)]
vis = [[False]*Ydim for _ in xrange(Xdim)]

def prB():
    print u'\u001b[2J'
    for b in board:
        print ''.join(b)

for ln in xlns:
    for i in xrange(ln[1],ln[2]+1):
        board[i-minX][ln[0]-minY] = '#'
for ln in ylns:
    for i in xrange(ln[1],ln[2]+1):
        board[ln[0]-minX][i-minY] = '#'
ogboard = [b[:] for b in board]

def valid(x, y):
    return x and y and x < Xdim and y < Ydim

def flowDown(x, y, mk):
    global mut
    if not valid(x+1, y):
        return False
    if vis[x][y]:
        return False

    vis[x][y] = True
    if mk:
        board[x][y] = '|'
    if board[x+1][y] == '.':
        return flowDown(x+1, y, mk)
    if not mk or board[x+1][y]!='|':
        return flowLR(x,y, mk)
    return False

def flowLR(x,y, mk):
    global mut
    ly, ry = y, y
    bndl=False
    while valid(x, ly-1):
        if board[x+1][ly-1]=='.':
            break
        if board[x][ly-1] == '#':
            bndl = True
            break
        ly-=1
    bndr=False
    while valid(x, ry+1):
        if board[x+1][ry+1]=='.':
            break
        if board[x][ry+1] == '#':
            bndr = True
            break
        ry+=1

    if bndl and bndr:
        mut = True
        for i in xrange(ly,ry+1):
            board[x][i] = '~'
        return True
    res = False
    if not bndr:
        res |= flowDown(x, ry+1, mk)
    if not bndl:
        res |= flowDown(x, ly-1, mk)
    if mk:
        for i in xrange(ly,ry+1):
            board[x][i] = '|'
    return res

def run():
    #prB()
    global mut, vis
    mut=True
    while mut:
        mut=False
        flowDown(0, 500-minY, True)
        vis = [[False]*Ydim for _ in xrange(Xdim)]
        prB()
        time.sleep(0.1)
        pass
    vis = [[False]*Ydim for _ in xrange(Xdim)]
    flowDown(0, 500-minY, True)

    #fancyPr()

    bcnt = 0
    cnt = 0
    for i in xrange(3, Xdim-2):
        for j in xrange(Ydim):
            if board[i][j] in ['~','|']:
                cnt+=1
            if board[i][j] in ['~']:
                bcnt+=1
    print cnt
    print bcnt

def mvUp(n):
    print u'\u001b[%dA' % n
def mvDown(n):
    print u'\u001b[%dB' % n
def mvRight(n):
    print u'\u001b[%dC' % n
def mvLeft(n):
    print u'\u001b[%dD' % n
def fancyPr():
    print u'\u001b[2J'
    for b in ogboard:
        print ''.join(b)
    mvUp(len(board)+1)
    for b in board:
        time.sleep(1)
        print ''.join(b)
run()
