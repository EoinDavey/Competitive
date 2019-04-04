from collections import defaultdict, deque
N, M, k = map(int, input().split())

def dist(a,b):
    return (a[1]-b[1])**2 + (a[2]-b[2])**2 + (a[3]-b[3])**2 

pts = []
cls = defaultdict(set)
BOUND = 100
starMp = {}
for _ in range(N):
    l = input().split()
    x, y, z = l[-3],l[-2],l[-1]
    nm = ' '.join(l[:-3])
    x, y, z = map(float, [x,y,z])
    pts.append((nm,x,y,z))
    starMp[nm] = (nm, x,y,z)

ls = [
        sorted(pts, key=lambda sK: (sK[1],sK[2],sK[3],sK[0])),
        sorted(pts, key=lambda sK: (sK[2],sK[1],sK[3],sK[0])),
        sorted(pts, key=lambda sK: (sK[3],sK[1],sK[2],sK[0])),
        sorted(pts, reverse = True, key=lambda sK: (sK[1],sK[2],sK[3],sK[0])),
        sorted(pts, reverse = True, key=lambda sK: (sK[2],sK[1],sK[3],sK[0])),
        sorted(pts, reverse = True, key=lambda sK: (sK[3],sK[1],sK[2],sK[0])),
]

def fCls(ind):
    global ls
    d = deque()
    for pt in ls[ind]:
        for p in d:
            cls[pt[0]].add(p)
        if len(d) == BOUND:
            d.popleft()
        d.append(pt)

for i in range(len(ls)):
    fCls(i)

for _ in range(M):
    ke = input()
    cur = starMp[ke]
    cls[ke] = list(cls[ke])
    cls[ke].sort(key=lambda x: (dist(x, cur), x[0]))
    print(ke+": ",end='')
    print(', '.join(map(lambda x: x[0], cls[ke][:k])))
