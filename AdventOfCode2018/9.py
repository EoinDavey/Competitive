import sys
from collections import Counter, deque

'''
ls = [line.strip() for line in sys.stdin]

for l in ls:
    pass
'''

s = raw_input().split()
n = int(s[0])
last = int(s[6])

circ = [0]
curM = 0
curE = 0
scr = [0]*n

for i in xrange(1, last+1):
    if i%23==0:
        scr[curE]+=i
        ind = ((curM - 7)+len(circ)) % len(circ)
        scr[curE]+=circ[ind]
        del circ[ind]
        curM = ind
    else:
        ind = (curM + 2)%len(circ) if len(circ) > 2 else 1
        circ.insert(ind, i)
        curM = ind
    curE = (curE+1)%n
print max(scr)
