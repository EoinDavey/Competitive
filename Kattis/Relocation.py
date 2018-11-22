N, Q = map(int, raw_input().split())
pos = {}
p = map(int, raw_input().split())
for i in xrange(N):
    pos[i+1]=p[i]

for _ in xrange(Q):
    l = raw_input().split()
    if l[0]=='1':
        pos[int(l[1])] = int(l[2])
    else:
        print abs(pos[int(l[1])] - pos[int(l[2])])
