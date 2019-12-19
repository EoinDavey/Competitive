from collections import defaultdict
N = int(input())

ps = [-1] + [int(x) for x in input().split()]
gph = defaultdict(list)

ranges = [(-1, -1) for _ in range(N)]
vals = [0]*N
order = [0]*N
tree = [0]*(N+1)

def lsOne(i):
    return i&(-i)

def update(k, v):
    while k <= N:
        tree[k] += v
        k += lsOne(k)

def query(k):
    sm = 0
    while k:
        sm += tree[k]
        k -= lsOne(k)
    return sm

def findOrder(u):
    st = [u]
    o = 1
    while st:
        u = st.pop()
        order[u] = o
        o += 1
        for v in gph[u]:
            st.append(v)

for i in range(1, N):
    gph[ps[i]].append(i)

findOrder(0)
ls = list(range(N))
ls.sort(key=lambda x: -order[x])

rngR = [x for x in order]
for x in ls:
    if ps[x] == -1:
        continue
    rngR[ps[x]] = max(rngR[ps[x]], rngR[x])

Q = int(input())

for _ in range(Q):
    ns = [int(x) for x in input().split()]
    if ns[0] == 1:
        u, v = ns[1:]
        update(order[u], v)
    else:
        u = ns[1]
        l, r = order[u], rngR[u]
        print(query(r) - query(l-1))
