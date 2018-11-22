perms = [
        [0,1,2,3,4,5],
        [0,1,4,5,3,2],
        [0,1,3,2,5,4],
        [0,1,5,4,2,3],
        [1,0,2,3,5,4],
        [1,0,5,4,3,2],
        [1,0,3,2,4,5],
        [1,0,4,5,2,3],
        [2,3,0,1,5,4],
        [2,3,5,4,1,0],
        [2,3,1,0,4,5],
        [2,3,4,5,0,1],
        [3,2,1,0,5,4],
        [3,2,0,1,4,5],
        [3,2,5,4,0,1],
        [3,2,4,5,1,0],
        [4,5,0,1,2,3],
        [4,5,1,0,3,2],
        [4,5,3,2,0,1],
        [4,5,2,3,1,0],
        [5,4,1,0,2,3],
        [5,4,0,1,3,2],
        [5,4,2,3,0,1],
        [5,4,3,2,1,0],
]

def apperm(p, i):
    return ''.join(map(lambda x: p[perms[i][x]], xrange(len(p))))

s = set()

def ins(l):
    global s
    for p in xrange(len(perms)):
        k = apperm(l, p)
        if k in s:
            return
    s.add(l)

def unq(l):
    for p in xrange(len(perms)):
        k = apperm(l, p)
        if k in s:
            return k

for a in xrange(1,7):
    for b in xrange(1,7):
        for c in xrange(1,7):
            for d in xrange(1,7):
                for e in xrange(1,7):
                    for f in xrange(1,7):
                        l = ''.join(map(str, [a,b,c,d,e,f]))
                        ins(l)

cnt = {}
for _ in xrange(input()):
    l = raw_input().replace(' ','')
    u = unq(l)
    if u in cnt:
        cnt[u] +=1
    else:
        cnt[u] = 1
print max(cnt.values())
