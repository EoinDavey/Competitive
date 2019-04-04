board = {}
mvs = [(0,1),(0,-1),(1,0),(-1,0),(-1,-1),(1,1),(-1,1),(1,-1)]
def ar((x,y)):
    o = []
    for j in xrange(len(mvs)):
        o.append((x+mvs[j][0], y+mvs[j][1]))
    return o

def val(pos):
    s = 0
    for p in ar(pos):
        if p in board:
            s+= board[p]
    return s

def solve(a):
    global board

    sl = 1
    x, y = 0, 0
    board[(0,0)] = 1

    while True:
        sl+=2
        #move to next layer
        x, y = x+1, y
        c=val((x,y))
        board[(x,y)] = c
        if c > a:
            return c
        #move (sl-2) up
        for _ in xrange(sl-2):
            x, y = x, y+1
            c=val((x,y))
            board[(x,y)] = c
            if c > a:
                return c
        #move (sl-1) left
        for _ in xrange(sl-1):
            x, y = x-1, y
            c=val((x,y))
            board[(x,y)] = c
            if c > a:
                return c
        #move (sl-1) down
        for _ in xrange(sl-1):
            x, y = x, y-1
            c=val((x,y))
            board[(x,y)] = c
            if c > a:
                return c
        #move (sl-1) right
        for _ in xrange(sl-1):
            x, y = x+1, y
            c=val((x,y))
            board[(x,y)] = c
            if c > a:
                return c

print solve(input())
