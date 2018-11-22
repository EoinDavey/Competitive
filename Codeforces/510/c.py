import sys
n = input()
a = map(int, raw_input().split())

negCnt = 0
for x in a:
    if x < 0:
        negCnt+=1

if negCnt %2:
    ind = max(filter(lambda x: a[x] < 0, range(n)), key=lambda x: a[x])
    a[ind] = 0

zeros = filter(lambda x: a[x]==0, range(n))

if len(zeros):
    mxi = zeros[-1]
    for z in zeros[:-1]:
        print 1, z+1, mxi+1
    if len(zeros) < n:
        print 2, mxi+1

nz = filter(lambda x: a[x]!=0, range(n))
if len(nz):
    mxi = nz[-1]
    for z in nz[:-1]:
        print 1, z+1, mxi+1
