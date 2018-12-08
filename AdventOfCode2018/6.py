import sys

ls = [map(int, line.strip().split(',')) for line in sys.stdin] # read in

board = [[-1]*1000 for _ in xrange(1000)] # 2d list of -1s, -1 means no closest

# loop over 2d board
for x in xrange(len(board)):
    for y in xrange(len(board[x])):
        cls = -1 # index of ls that is closest
        mn = 10**18
        st = True # strict miniumum

        for i in xrange(len(ls)):
            d = abs(ls[i][0] - x) + abs(ls[i][1] - y)
            if d < mn:
                mn = d
                cls = i
                st = True
            elif d==mn:
                st = False
        if st:
            board[x][y] = cls
        else:
            board[x][y] = -1

inf = set() # infinite areas
inf.add(-1)

for x in xrange(len(board)): #add all edges to infinite
    inf.add(board[x][0])
    inf.add(board[x][-1])
    inf.add(board[0][x])
    inf.add(board[-1][x])

cnt = {} #cnt is the amount of each area
for x in xrange(len(board)):
    for y in xrange(len(board[x])):
        if board[x][y] not in cnt:
            cnt[board[x][y]] = 0
        cnt[board[x][y]] += 1

# get biggest area not infinite
mx = 0
for k, v in cnt.items():
    if k not in inf:
        mx = max(mx, v)

s = 0
for i in xrange(-500, 900):
    for j in xrange(-500, 900):
        sm = 0
        for (x,y) in ls:
            sm += abs(x-i) + abs(y-j)
        if sm < 10000:
            s+=1

print mx
print s
