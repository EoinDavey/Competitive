import sys
from collections import Counter, deque

curboard = [list(line[:-1]) for line in sys.stdin]
netboard = [curboard[x][:] for x in xrange(len(curboard))]

for i in xrange(len(netboard)):
    for j in xrange(len(netboard[0])):
        if netboard[i][j] == '>':
            netboard[i][j] = '-'
        if netboard[i][j] == '<':
            netboard[i][j] = '-'
        if netboard[i][j] == '^':
            netboard[i][j] = '|'
        if netboard[i][j] == 'v':
            netboard[i][j] = '|'

carts = ['<', '>', 'v', '^']
crtCount = 0
for i in xrange(len(netboard)):
    for j in xrange(len(netboard[0])):
        if curboard[i][j] in carts:
            crtCount += 1

curboard = [curboard[x][:] for x in xrange(len(curboard))]

dirs = [[0]*len(curboard[0]) for _ in xrange(len(curboard))]


def proc(x, y):
    global curboard, carts, dirs, crtCount
    if curboard[x][y] == '>':
        nx, ny = x, y+1
        if curboard[nx][ny] in carts:
            crtCount -= 2
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = netboard[nx][ny]
            print nx, ny
            return True
        if curboard[nx][ny] == '-':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '>'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '\\':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = 'v'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '/':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '^'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '+':
            if dirs[x][y] == 0:
                # left
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '^'
            if dirs[x][y] == 1:
                # straight
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '>'
            if dirs[x][y] == 2:
                # right
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = 'v'
            dirs[nx][ny] = (dirs[x][y] + 1) % 3
    elif curboard[x][y] == '<':
        nx, ny = x, y-1
        if curboard[nx][ny] in carts:
            crtCount -= 2
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = netboard[nx][ny]
            print nx, ny
            return True
        if curboard[nx][ny] == '-':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '<'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '/':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = 'v'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '\\':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '^'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '+':
            if dirs[x][y] == 0:
                # left
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = 'v'
            if dirs[x][y] == 1:
                # straight
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '<'
            if dirs[x][y] == 2:
                # right
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '^'
            dirs[nx][ny] = (dirs[x][y] + 1) % 3
    elif curboard[x][y] == 'v':
        nx, ny = x+1, y
        if curboard[nx][ny] in carts:
            crtCount -= 2
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = netboard[nx][ny]
            print nx, ny
            return True
        if curboard[nx][ny] == '|':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = 'v'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '/':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '<'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '\\':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '>'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '+':
            if dirs[x][y] == 0:
                # left
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '>'
            if dirs[x][y] == 1:
                # straight
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = 'v'
            if dirs[x][y] == 2:
                # right
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '<'
            dirs[nx][ny] = (dirs[x][y] + 1) % 3
    elif curboard[x][y] == '^':
        nx, ny = x-1, y
        if curboard[nx][ny] in carts:
            crtCount -= 2
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = netboard[nx][ny]
            print nx, ny
            return True
        if curboard[nx][ny] == '|':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '^'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '/':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '>'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '\\':
            curboard[x][y] = netboard[x][y]
            curboard[nx][ny] = '<'
            dirs[nx][ny] = dirs[x][y]
        elif curboard[nx][ny] == '+':
            if dirs[x][y] == 0:
                # left
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '<'
            if dirs[x][y] == 1:
                # straight
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '^'
            if dirs[x][y] == 2:
                # right
                curboard[x][y] = netboard[x][y]
                curboard[nx][ny] = '>'
            dirs[nx][ny] = (dirs[x][y] + 1) % 3
    return False

def solvea():
    while True:
        cpboard = [curboard[x][:] for x in xrange(len(curboard))]
        for i in xrange(len(curboard)):
            for j in xrange(len(curboard[i])):
                if cpboard[i][j] in carts:
                    if proc(i, j):
                        return
def solveb():
    while True:
        lst = crtCount == 1
        cpboard = [curboard[x][:] for x in xrange(len(curboard))]
        for i in xrange(len(curboard)):
            for j in xrange(len(curboard[i])):
                if cpboard[i][j] in carts:
                    proc(i, j)
        if lst:
            for i in xrange(len(curboard)):
                for j in xrange(len(curboard[i])):
                    if cpboard[i][j] in carts:
                        print j, i
            return

solveb()
