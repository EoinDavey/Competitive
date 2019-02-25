import sys
import time
from collections import Counter, deque, defaultdict

mvs = [(1,1),(-1,-1),(1,-1),(-1,1),(0,1),(1,0),(-1,0),(0,-1)]

board = [list(line.strip()) for line in sys.stdin]
boards = [board, [b[:] for b in board]]

def valid(i, j):
    return i>=0 and j>=0 and i < len(board) and j < len(board[0])

def count(i, j, ind):
    op = 0
    w = 0
    l = 0
    for di, dj in mvs:
        ni = i + di
        nj = j + dj
        if not valid(ni, nj):
            continue
        if boards[ind][ni][nj] == '.':
            op+=1
        if boards[ind][ni][nj] == '|':
            w+=1
        if boards[ind][ni][nj] == '#':
            l+=1
    return op, w , l

def prB():
    print u'\u001b[2J'
    for b in board[:100]:
        print ''.join(b)
    time.sleep(0.1)

ind = 0
for t in xrange(1, 1000000000):

    ind = 1-ind
    for i in xrange(len(board)):
        for j in xrange(len(board[0])):
            o, w, l = count(i, j, 1-ind)
            if boards[1-ind][i][j] == '.' and w >= 3:
                boards[ind][i][j] = '|'
            elif boards[1-ind][i][j] == '|' and l >= 3:
                boards[ind][i][j] = '#'
            elif boards[1-ind][i][j] == '#':
                if l and w:
                    boards[ind][i][j] = '#'
                else:
                    boards[ind][i][j] = '.'
            else:
                boards[ind][i][j] = boards[1-ind][i][j]
    prB()

    if t%1000 == 0:
        w = 0
        l = 0
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if boards[ind][i][j]=='|':
                    w+=1
                if boards[ind][i][j]=='#':
                    l+=1
        print t, w*l

w = 0
l = 0
for i in xrange(len(board)):
    for j in xrange(len(board[0])):
        if boards[ind][i][j]=='|':
            w+=1
        if boards[ind][i][j]=='#':
            l+=1
print w*l
