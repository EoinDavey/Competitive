from collections import Counter

N, H = *map(int, input().split()),
pile = *map(int, input().split()),

c = Counter(pile).most_common()
freqs = [x[1] for x in c]

def tst(k):
    global cnt
    sm = 0
    for x in freqs:
        sm += min(x, k)
    return sm // k >= H

def bld(k):
    global cnt
    hnds = [[] for _ in range(k)]
    i = 0
    for (v, f) in c:
        for _ in range(min(k, f)):
            hnds[i].append(str(v))
            i = (i + 1) % k
    for hnd in hnds:
        print(' '.join(hnd[:k]))

L = 1
R = 10**6+10

while L < R:
    md = (L + R + 1)//2
    if tst(md):
        L = md
    else:
        R = md-1

if tst(L):
    bld(L)
else:
    print("impossible")
