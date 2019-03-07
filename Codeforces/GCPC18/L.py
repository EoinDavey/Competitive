h, w = map(int, raw_input().split())

h+=2
w+=2

board = [map(int, raw_input().split()) for _ in xrange(h)]
ogb = [b[:] for b in board]
o = [[False]*w for _ in xrange(h)]
c = [[0]*w for _ in xrange(h)]

def isvalid(i,j):
    return i >= 0 and j >= 0 and i < h and j < w

def dec(x,y):
    for dx, dy in [(0,0), (1,1), (1,-1), (-1,1), (-1,-1), (0,1),(1,0),(-1,0),(0,-1)]:
        nx,ny = x+dx,y+dy
        if isvalid(nx,ny):
            board[nx][ny]-=1

def inc(x,y):
    for dx, dy in [(0,0), (1,1), (1,-1), (-1,1), (-1,-1), (0,1),(1,0),(-1,0),(0,-1)]:
        nx,ny = x+dx,y+dy
        if isvalid(nx,ny):
            c[nx][ny]+=1

for x in xrange(h-2):
    for y in xrange(w-2):
        if board[x][y] == 1:
            o[x+1][y+1] = True
            dec(x+1,y+1)

for x in xrange(h):
    for y in xrange(w):
        if o[x][y]:
            inc(x,y)

if ogb == c:
    for i in xrange(1,h-1):
        print ''.join(map(lambda x: 'X' if x else '.', o[i][1:-1]))
else:
    print "impossible"
