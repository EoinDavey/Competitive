import sys
cnt = 0
ls = [-1]*100
def check(de):
    pos = [0]*100
    dr = [1]*100
    for _ in xrange(de):
        for x in xrange(100):
            if ls[x] != -1:
                pos[x] += dr[x]
                if pos[x] == 0:
                    dr[x] = 1
                elif pos[x] == ls[x]-1:
                    dr[x]=-1

    for t in xrange(100):
        if ls[t]!=-1 and pos[t]==0:
            return False

        for x in xrange(100):
            if ls[x] != -1:
                pos[x] += dr[x]
                if pos[x] == 0:
                    dr[x] = 1
                elif pos[x] == ls[x]-1:
                    dr[x]=-1
    return True

for line in sys.stdin:
    l = line.strip().split()
    a = int(l[0][:-1])
    b = int(l[1])
    ls[a] = b

de = 0
while True:
    if(de % 1000 == 0):
        print de
    if check(de):
        print de
        break
    de+=1
