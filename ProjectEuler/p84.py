import numpy as np

cnt = [0]*40

pos = 0
dRun=0
GO = 0
JAIL = 10
G2J = 30
CC = [2,17,33]
CCH = [7,22,36]
RS = [5,15,25,35]
US = [12,28]

cch = []
ch = []

def id():
    #print "nothing"
    return

def goToInd(x):
    def _go():
        global pos
        #print "Go to %d" % x
        pos = x
    return _go

def goToNext(xs):
    def _go():
        #print "Go to next from ", xs
        global pos
        if pos >= xs[len(xs)-1]:
            pos = xs[0]
            return
        for x in xs:
            if pos < x:
                #print "Go to ",x
                pos = x
                break
    return _go

def goBack():
    def _go():
        global pos
        #print "Go back 3"
        pos = (pos-3)%40;
    return _go

def setup():
    global cch,ch,pos
    pos = 0
    c = [goToInd(GO),goToInd(JAIL)] + [id]*14;
    cch = np.random.permutation(c).tolist()
    c = [goToInd(i) for i in [GO,JAIL,11,24,39,5]]
    c+= [goToNext(RS),goToNext(RS), goToNext(US), goBack()]
    c+=[id]*6
    ch = np.random.permutation(c).tolist()

def turn():
    global pos,cch,ch,dRun
    r1=np.random.randint(1,5)
    r2=np.random.randint(1,5)
    roll = r1+r2
    if r1==r2:
        dRun+=1
    else:
        dRun=0
    if dRun==3:
        pos = JAIL
        dRun=0
    else:
        pos = (pos + roll) % 40
    if pos in CCH:
        #print "Community Chest"
        action = cch[0]
        cch = cch[1:]
        cch.append(action)
        action()
    if pos in CC:
        #print "Chance"
        action = ch[0]
        ch = ch[1:]
        ch.append(action)
        action()
    if pos == G2J:
        pos = JAIL
    cnt[pos]+=1

setup()
for _ in range(1000000):
    turn()

cnt = zip(cnt,range(40))
cnt.sort(reverse=True)
print cnt
