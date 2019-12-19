import random
import sys
from collections import defaultdict

sys.setrecursionlimit(1000)

if len(sys.argv) < 2 :
    sys.exit(1)

TOT = int(sys.argv[1])

p = {}
ps = []
adjList = defaultdict(list)
vis = set()
def find(i):
    if i == p[i]:
        return i
    p[i] = find(p[i])
    return p[i]

def join(a, b):
    p[find(a)] = find(b)

def dfs(u):
    vis.add(u)
    for v in adjList[u]:
        if v in vis:
            continue
        ps[v] = u
        dfs(v)

def gen(N):
    global p, adjList, ps
    p = {}
    ps = [-1]*N
    vis = set()

    for i in range(N):
        p[i] = i

    adjList = defaultdict(list)
    cnt = 0
    while cnt < N - 1:
        a = random.randint(0, N - 1)
        b = random.randint(0, N - 1)
        if a == b or find(a) == find(b):
            continue
        join(a, b)
        cnt += 1
        adjList[a].append(b)
        adjList[b].append(a)
    dfs(0)
    print(N)
    print(' '.join(map(str, ps[1:])))
    print(N)
    for _ in range(N):
        if random.random() > 0.5:
            u, v = random.randint(0, N - 1), random.randint(1, 1000)
            print(1, u, v)
        else:
            u = random.randint(0, N - 1)
            print(2, u)
gen(TOT)
