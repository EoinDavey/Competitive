from random import randint, random
from math import log
import sys

NQLIM = 2*(10**5)
TGRLIM = 10**9

if len(sys.argv) < 2 :
    sys.exit(1)

N = int(sys.argv[1])

rngR = 10*N

tgrs = []
stedtgrs = sorted(tgrs)
for _ in range(N):
    tgr = randint(0, min(TGRLIM, rngR))
    tgrs.append(tgr)

Q = randint(N//2, min(NQLIM, 2*N))
qs = []

for _ in range(Q):
    li = randint(0, N - 1)
    ri = randint(0, N - 1)
    if li > ri:
        li, ri = ri, li

    var = int(log(N))
    lv = randint(max(0, tgrs[li]-var), min(TGRLIM, tgrs[li]+var))
    rv = randint(max(0, tgrs[ri]-var), min(TGRLIM, tgrs[ri]+var))

    if lv > rv:
        lv, rv = rv, lv
    qs.append((lv, rv))

print(N)
print(' '.join(map(str, tgrs)))
print(Q)
for (l, r) in qs:
    print(l, r)
