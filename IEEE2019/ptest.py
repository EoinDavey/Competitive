from math import gcd
from collections import defaultdict, deque

lim = 10**5 + 10
sieve = [0]*lim
sieve[1] = 1

for i in range(2, lim):
    if sieve[i] == 0:
        for j in range(i, lim, i):
            sieve[j] = i

N, K = [int(x) for x in input().split()]
As = [int(x) for x in input().split()]

pmap = defaultdict(list)
for i in As:
    if i == 1:
        #TODO
        continue

    p = i
    ps = set()
    while p > 1:
        ps.add(sieve[p])
        p //= sieve[p]

    for p in ps:
        pmap[p].append(i)

for p in pmap:
    pmap[p].sort()

dist = defaultdict(lambda: 10**10)
def srchFrom(ls):
    global dist
    q = deque()
    for i in range(len(ls)):
        q.append(ls[i])
        dist[ls[i]] = 1

    while q:
        u = q.popleft()

        if dist[u] + 1 >= K:
            continue

        p = u
        ps = set()
        while p > 1:
            ps.add(sieve[p])
            p //= sieve[p]

        for pr in ps:
            for x in pmap[pr]:
                if gcd(x, u) == u:
                    break
                v = gcd(x,u)
                if dist[v] > dist[u] + 1:
                    dist[v] = dist[u] + 1;
                    q.append(v)

srchFrom(As)
cnt = 0
for _, v in dist.items():
    if v <= K:
        cnt += 1
print(cnt)
