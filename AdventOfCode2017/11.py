from collections import deque

ods = [(0,-1),(1,0),(1,1),(0,1),(-1,1), (-1,0)]
evs = [(0,-1), (1,-1),(1,0),(0, 1), (-1, 0), (-1, -1)]

ind = {
        'n':0,
        'ne':1,
        'se':2,
        's':3,
        'sw':4,
        'nw':5
}

def mvs((x,y)):
    o = []
    if x%2:
        for (dx,dy) in ods:
            o.append((x+dx,y+dy))
    else:
        for (dx,dy) in evs:
            o.append((x+dx,y+dy))
    return o

l = raw_input().split(',')

mvQ = deque()
x, y = 0, 0
for mv in l:
    i = ind[mv]
    if x%2:
        x,y = x+ods[i][0], y+ods[i][1]
    else:
        x,y = x+evs[i][0], y+evs[i][1]
    mvQ.append((x,y))

fx = x;fy=y

d = deque()
d.append((0,0,0))
vis = {}
vis[(0,0)] = 0
mx = 0
while d:
    x,y,dis = d.popleft()
    while mvQ and mvQ[0] in vis:
        mx = max(mx, vis[mvQ.popleft()])
    if not mvQ:
        break
    for p in mvs((x,y)):
        if (p[0],p[1]) not in vis:
            d.append((p[0],p[1],dis+1))
            vis[(p[0],p[1])] = dis+1
print mx
