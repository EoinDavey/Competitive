# board = [lane]
# lane = {dir, O, I, V}
# dir = 0 -> LTR, 1 -> RTL

def newLane(lane):
    d, O, I, V = lane
    return d, (O+V)%W, I, V

def redZ(lane):
    d, O, I, V = lane
    if V >= I:
        return [True]*W

    red = [False]*W
    for pos in xrange(W):
        np = (pos-O + I)%I
        red[pos] = np > 0 and np <= V
    if d:
        return red[::-1]
    return red

def getNextBoard(board):
    return map(newLane, board)

L, W = map(int, raw_input().split())
board = []
for j in xrange(L):
    o,i,v = map(int, raw_input().split())
    board.append((j%2,o,i,v))

board = board[::-1]

PM = raw_input().split()
P = int(PM[0])
M = PM[1]
x = P
y = -1

for c in M:
    if c=='U':
        if y < L:
            y+=1
    elif c=='D':
        if y > -1:
            y-=1
    elif c=='L':
        if x > 0:
            x-=1
    elif c=='R':
        if x < W-1:
            x+=1
    if y >= 0 and y < L and x >= 0 and x < W:
        rL = redZ(board[y])
        if rL[x]:
            break
    board = getNextBoard(board)
if y >= L:
    print "safe"
else:
    print "squish"
