# coding=utf-8
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


for ln in xlns:
    for i in xrange(ln[1],ln[2]+1):
        board[i-minX][ln[0]-minY] = '#'
for ln in ylns:
    for i in xrange(ln[1],ln[2]+1):
        board[ln[0]-minX][i-minY] = '#'
ogboard = [b[:] for b in board]

def valid(x, y):
    return x and y and x < Xdim and y < Ydim

def flowDown(x, y):
    global mut
    if not valid(x+1, y) or vis[x][y]:
        return
    vis[x][y] = True

    board[x][y] = '|'
    if board[x+1][y] in ['.','|']:
        return flowDown(x+1, y)
    return flowLR(x,y)

def flowLR(x,y):
    global mut
    ly, ry = y, y
    bndl=False
    while valid(x, ly-1):
        if board[x+1][ly-1] in ['.', '|']:
            break
        if board[x][ly-1] == '#':
            bndl = True
            break
        ly-=1
    bndr=False
    while valid(x, ry+1):
        if board[x+1][ry+1] in ['.', '|']:
            break
        if board[x][ry+1] == '#':
            bndr = True
            break
        ry+=1

    for i in xrange(ly,ry+1):
        board[x][i] = '|'
    if bndl and bndr:
        mut = True
        for i in xrange(ly,ry+1):
            board[x][i] = '~'
        return
    if not bndr:
        flowDown(x, ry+1)
    if not bndl:
        flowDown(x, ly-1)

mp = {
        '|' : u'\u001b[34m█\u001b[0m',
        '~' : u'\u001b[34m█\u001b[0m',
        '#' : '#',
        '.' : ' '
}

def prB():
    print u'\u001b[2J'
    for b in board[:100]:
        print ''.join(map(lambda x: mp[x], b))
    time.sleep(0.2)

def run():
    global mut, vis
    mut=True
    while mut:
        mut=False
        flowDown(0, 500-minY)
        vis = [[False]*Ydim for _ in xrange(Xdim)]
        #prB()
        pass
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

run()
