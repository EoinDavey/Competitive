import sys
ls = [line for line in sys.stdin]

board = [[0]*1000 for _ in xrange(1000)]

for l in ls:
    l = l.strip().split()
    c = l[2]
    d = l[3]
    x, y = map(int,c[:-1].split(','))
    w, h = map(int,d.split('x'))

    for i in xrange(w):
        for j in xrange(h):
            nx = x + i
            ny = y +j
            board[nx][ny]+=1

for l in ls:
    l = l.strip().split()
    c = l[2]
    d = l[3]
    x, y = map(int,c[:-1].split(','))
    w, h = map(int,d.split('x'))

    ps = True
    for i in xrange(w):
        for j in xrange(h):
            nx = x + i
            ny = y +j
            if board[nx][ny] > 1:
                ps = False
    if ps:
        print l[0]
