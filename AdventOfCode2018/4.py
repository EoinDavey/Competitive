import sys
from collections import Counter

evs = []
for line in sys.stdin:
    l = line.strip().split()
    date = l[0][1:] + l[1][:-1]
    time = int(l[1][:-1].split(':')[1])
    action = l[2:]
    evs.append((date, time, action))

evs.sort()

grd = 0
tm = 0
slp = 0
cnt = {}
mnts = {}
for (date,time,action) in evs:
    if action[0]=='Guard':
        if grd:
            if grd in cnt:
                cnt[grd]+=tm
            else:
                cnt[grd]=tm
        grd = int(action[1][1:])
        tm = 0
    elif action[0]=='falls':
        slp = time
    elif action[0]== 'wakes':
        tm += time-slp
        if grd not in mnts:
            mnts[grd] = []
        for x in xrange(slp, time):
            mnts[grd].append(x)

'''
grd = max(cnt,key=lambda x: cnt[x])
c = Counter(mnts[grd])
d =  c.most_common(1)[0][0]
print grd,d
print grd*d
'''
mx = 0
for grd in cnt:
    if grd not in mnts:
        continue
    c = Counter(mnts[grd])
    (a,b) =  c.most_common(1)[0]
    if b > mx:
        mx = b
        print grd * a

