import sys
from collections import Counter, deque

ls = [line.strip() for line in sys.stdin]

inst = ls[0].split()[-1]
print len(inst)
inst = "".join(["."]*300) + inst + "".join(["."]*300)

mvs = {}

for l in ls[2:]:
    l, c, r = l.split()
    mvs[l] = r


def newst(st):
    newO = ".."
    for i in xrange(2, len(st)):
        if st[i-2:i+3] in mvs:
            newO += mvs[st[i-2:i+3]]
        else:
            newO += '.'
    return newO

for j in xrange(1,250):
    inst = newst(inst)

    tot = 0
    for i in xrange(len(inst)):
        if inst[i]=='#':
            tot+=i-300
    print j, tot
