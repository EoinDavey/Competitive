MX_R=1001;MX_SMD=80;MX_N=2002;
MX_LM = 10**18
R=S=M=D=N=0;
b = [0]*MX_R
ing = [[0]*MX_R for _ in range(MX_SMD)]
adjMat = [[True]*MX_SMD for _ in range(MX_SMD)]
cnt = [0]*MX_R;
fail = False

def add(a,b):
    global fail
    t = a+b
    if t > MX_LM:
        fail = True
    return t

def mult(a,b):
    global fail
    t = a*b
    if t > MX_LM:
        fail = True
    return t

[R,S,M,D,N] = map(int,raw_input().split())
b = map(int,raw_input().split())

for i in xrange(S+M+D):
    xs = map(int,raw_input().split())[1:]
    for x in xs:
        ing[i][x-1] = True

for i in xrange(N):
    [i1,i2] = map(int,raw_input().split())
    i1-=1; i2-=1
    if i2 < i1:
        t = i1
        i1 = i2
        i2 = t
    adjMat[i1][i2] = False;

res = 0
for i in xrange(0,S):
    for j in xrange(S,S+M):
        if not adjMat[i][j]:
            continue
        for k in xrange(S+M,S+M+D):
            if not adjMat[i][k] or not adjMat[j][k]:
                continue
            o = 1
            for r in xrange(R):
                if ing[i][r] or ing[j][r] or ing[k][r]:
                    o*=b[r]
            res += o

if fail or res > MX_LM or res < 0:
    print "too many"
else:
    print res
