import sys
from collections import Counter, deque


pws = [[0]*300 for _ in xrange(300)]

s = input()

for x in xrange(300):
    x+=1
    rckId = x+10
    for y in xrange(300):
        y+=1

        pw = y*rckId
        pw += s
        pw *= rckId

        pw = (pw/100) % 10
        pw -= 5
        pws[x-1][y-1] = pw

ans = (0,0)
mx = -10**18

for x in xrange(300):
    if x + 3 > 300:
        break
    for y in xrange(300):
        if y + 3 > 300:
            break
        tot = 0
        for i in xrange(3):
            for j in xrange(3):
                tot += pws[x+i][y+j]
        if tot > mx:
            mx  =tot
            ans = (x+1, y+1)
print ans
