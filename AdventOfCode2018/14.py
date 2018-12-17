import sys
from collections import Counter, deque

def ls(x):
    if x > 9:
        return [1, x-10]
    return [x]

ins = raw_input()
s = int(ins)

tgt = map(int, list(ins))
print tgt

l = [3, 7]
cur = [0, 1]

curW = [3, 7]
def solve():
    while True:
        n = ls(l[cur[0]] + l[cur[1]])
        for x in n:
            l.append(x)
            curW.append(x)
            while len(curW) > len(tgt):
                curW.pop(0)
            if curW == tgt:
                print len(l) - len(tgt)
                return
        cur[0] = (cur[0] + 1 + l[cur[0]]) % len(l)
        cur[1] = (cur[1] + 1 + l[cur[1]]) % len(l)

solve()
'''
o = ""
for i in xrange(10):
    o += str(l[s+i])
print o
'''
