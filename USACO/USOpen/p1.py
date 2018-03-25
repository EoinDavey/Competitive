fin = open("tttt.in","r")
fout = open("tttt.out","w+")
board = [x.strip('\n') for x in fin.readlines()]

def checkIndex(s,xs):
    for (a,b) in xs:
        if board[a][b] not in s:
            return False
    for x in s:
        if not any(map(lambda (a,b): board[a][b]==x,xs)):
            return False
    return True

def checkWin(s):
    if any(map(lambda x: checkIndex(s,x), [[(0,0),(1,1),(2,2)],[(0,0),(0,1),(0,2)],[(1,0),(1,1),(1,2)],[(2,0),(2,1),(2,2)],[(0,2),(1,1),(2,0)],[(0,0),(1,0),(2,0)],[(0,1),(1,1),(2,1)],[(0,2),(1,2),(2,2)]])):
        return True
    return False

o = len(filter(lambda x: checkWin([chr(x+ord('A'))]), range(26)))
fout.write(str(o))
fout.write("\n")
fout.write(str(len(filter(lambda (x,y): checkWin([chr(x+ord('A')),chr(y+ord('A'))]), [(a,b) for a in range(26) for b in range(a+1,26)]))))
fout.write("\n")
fin.close()
fout.close()
