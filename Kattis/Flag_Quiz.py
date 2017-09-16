_ = raw_input()
N = int(raw_input())

tks = [raw_input().split(",") for _ in xrange(N)]

ans = tks[0]
mnincon = 100000
for t in tks:
    mxincon = 0
    for x in tks:
        incon = 0
        for i in xrange(len(t)):
            if t[i] != x[i]:
                incon+=1
        mxincon = max(mxincon,incon)
    mnincon = min(mnincon,mxincon)

for t in tks:
    mxincon = 0
    for x in tks:
        incon = 0
        for i in xrange(len(t)):
            if t[i] != x[i]:
                incon+=1
        mxincon = max(mxincon,incon)
    if mxincon==mnincon:
        print ",".join(t)
