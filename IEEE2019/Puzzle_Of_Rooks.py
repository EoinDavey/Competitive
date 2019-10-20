from collections import defaultdict
mvs = [(0,1), (1,0), (-1,0), (0,-1)]

def rdP():
    x = [int(x) for x in input().split()]
    return (x[0],x[1])

N = int(input())
rks = [rdP() for _ in range(N)]
tgts = [rdP() for _ in range(N)]

def dist(x, y):
    a,b = x
    c,d = y
    return abs(a-c) + abs(b-d)

def assign(rks, tgts):
    usd = set()
    mp = {}
    for i in range(len(tgts)):
        tgt = tgts[i]
        rk = min(filter(lambda x: x not in usd, range(len(rks))), key=lambda x: dist(rks[x], tgt))
        usd.add(rk)
        mp[tgt] = rk

    return mp

def sgn(x):
    return -1 if x < 0 else 1

def solved():
    st = set(poss)
    tgst = set(tgts)
    return st == tgst

def valid():
    rcnt = defaultdict(int)
    ccnt = defaultdict(int)
    for i in range(N):
        if hold == i:
            continue
        x, y = poss[i]
        rcnt[x]+=1
        ccnt[y]+=1
    for v in rcnt.values():
        if v > 1:
            return False
    for v in ccnt.values():
        if v > 1:
            return False
    return True

def visited():
    global poss, hold, vis
    return (tuple(poss) + (hold,)) in vis

asmt = assign(rks, tgts)

poss = [r for r in rks]
hold = -1
vis = set()

o = []
def move(rki, tgt):
    global hold, poss, vis
    print(rki,tgt,poss,hold)
    if poss[rki] == tgt:
        return True

    if visited():
        return False

    vis.add(tuple(poss) + (hold,))

    (x, y) = poss[rki]
    (tx, ty) = tgt

    mx = 0 if x == tx else sgn(tx-x)
    my = 0 if y == ty else sgn(ty-y)

    # Try move the "right way"
    nx = x + mx
    ny = y + my
    poss[rki] = (nx, ny)
    if hold != rki and valid() and move(rki, tgt):
        return True
    poss[rki] = (x,y)

    # Try remove the hold piece
    if hold != -1:
        ohold = hold
        hold = -1
        if valid() and move(rki, tgt):
            o.append("Put hold back")
            return True
        hold = ohold

    # Try put pieces in hold
    if hold == -1:
        # Put piece i in hold
        for i in range(N):
            hold = i
            if hold != rki and valid() and move(rki, tgt):
                o.append("Put %d on hold" % i)
                return True
            hold = -1

    for (dx, dy) in mvs:
        nx = x + dx
        ny = y + dy
        poss[rki] = (nx, ny)

        if hold != rki and valid() and move(rki, tgt):
            o.append("(%d,%d) -> (%d,%d)" % (x,y,nx,ny))
            return True
        poss[rki] = (x, y)

    return False

for i in range(N):
    tgt = tgts[i]
    rk = asmt[tgt]
    if not move(rk, tgt):
        print("Err",i)
