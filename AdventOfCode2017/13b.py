import sys
cnt = 0
ls = [-1]*100
posT = []

for line in sys.stdin:
    l = line.strip().split()
    a = int(l[0][:-1])
    b = int(l[1])
    ls[a] = b

pos = [0]*100
dr = [1]*100
for t in xrange(4000000):
    posT.append(pos[:])
    for x in xrange(100):
        if ls[x] != -1:
            pos[x] += dr[x]
            if pos[x] == 0:
                dr[x] = 1
            elif pos[x] == ls[x]-1:
                dr[x]=-1

de = 0
while True:
    fail = False
    for t in xrange(100):
        if ls[t]!=-1 and posT[t+de][t]==0:
            fail=True
            break
    if not fail:
        print de
        break
    de +=1
