import sys
boards = []
board = []
for line in sys.stdin:
    line = line[:-1]
    if line=="":
        boards.append(board)
        board=[]
    else:
        board.append(line)
boards.append(board)

def indof(b,i):
    h = len(b)
    for j in xrange(h):
        if b[j][i]=='*':
            return j

for b in boards:
    s = map(lambda x: (-indof(b,x),x),range(len(b[0])))
    order = map(lambda x: x[1],sorted(s))
    for i in xrange(len(b)):
        s = ""
        for j in xrange(len(b[0])):
            s+=b[i][order[j]]
        print s
    print

