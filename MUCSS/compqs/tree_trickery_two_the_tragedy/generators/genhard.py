import random
import sys
from collections import defaultdict

sys.setrecursionlimit(1000)

if len(sys.argv) < 2 :
    sys.exit(1)

TOT = int(sys.argv[1])

p = {i:i for i in range(TOT)}

ps = [-1]*TOT
adjList = defaultdict(list)
def find(i):
    if i == p[i]:
        return i
    p[i] = find(p[i])
    return p[i]

def join(a, b):
    p[find(a)] = find(b)

def dfs(u):
    vis = set()
    vis.add(u)
    st = [u]
    while st:
        u = st.pop()
        for v in adjList[u]:
            if v in vis:
                continue
            vis.add(v)
            st.append(v)
            ps[v] = u

shuf = list(range(TOT))
random.shuffle(shuf)
chainl = random.randint(max(TOT - 100, 1), TOT)
chain, rem = shuf[:chainl], shuf[chainl:]
assert(len(chain) == chainl)

for i in range(1, chainl):
    adjList[chain[i]].append(chain[i - 1])
    adjList[chain[i - 1]].append(chain[i])
    assert(find(chain[i - 1]) != find(chain[i]))
    join(chain[i], chain[i - 1])

for x in rem:
    while True:
        a = random.randint(0, TOT - 1)
        if find(x) != find(a):
            adjList[x].append(a)
            adjList[a].append(x)
            join(a, x)
            break

for i in range(1, TOT):
    assert(find(i) == find(i-1))

dfs(0)
for i in range(TOT):
    assert((ps[i] == -1) == (i == 0))
print(TOT)
print(' '.join(map(str, ps[1:])))

Q = random.randint(max(10, TOT-5), max(10, TOT))
print(Q)
for _ in range(Q):
    if random.random() > 0.5:
        u, v = random.randint(0, TOT - 1), random.randint(1, 1000)
        print(1, u, v)
    else:
        u = random.randint(0, TOT - 1)
        print(2, u)
