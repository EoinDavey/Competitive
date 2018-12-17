import time
import sys
from collections import Counter, deque

def add((a,b),(c,d)):
    return (a+c, b+d)

def pr(t):
    maxX = max(map(lambda x:x[0], pos))
    minX = min(map(lambda x:x[0], pos))
    maxY = max(map(lambda x:x[1], pos))
    minY = min(map(lambda x:x[1], pos))
    maxX -= minX
    maxY -= minY

    if maxX*maxY < 1000:

        board = [['.']*(maxY+1) for _ in xrange(maxX+1)]
        
        for (x,y) in pos:
            x-=minX
            y-=minY
            board[x][y] = '#'
        print t
        print '\n'.join(map(lambda x: ''.join(x), board))

pos = []
vel = []

ls = [line.strip() for line in sys.stdin]

for l in ls:
    l = l.split()
    x, y, dx, dy = map(int, [l[1][:-1], l[2][:-1], l[4][:-1], l[5][:-1]])
    pos.append((y,x))
    vel.append((dy,dx))

st = 0
while True:
    for i in xrange(len(pos)):
        pos[i] = add(pos[i], vel[i])
    st+=1
    pr(st)
