def evalp(cs,x):
    o = 0
    for i in xrange(len(cs)):
        o += cs[i]*(x**i)
    return o

cof = map(int, raw_input().split())[1:][::-1]
N = len(cof)
M = (N+1)
p = [evalp(cof,i) for i in xrange(0,M)]

def evalCon(s,c):
    o = 0
    for i in s:
        o+=c[ord(i)-ord('0')]
    return o

cs = [cof[0]]
t = [str(i) for i in xrange(N)]

for i in xrange(1,N):
    cs.append(p[i]-p[i-1] - evalCon(t[1][:-1],cs))
    for j in xrange(1,N-1):
        t[j] += t[j+1]

print " ".join(map(str,cs))
