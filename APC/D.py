from collections import defaultdict

n, K = [int(x) for x in input().split()]
adjList = defaultdict(list)

proving_cubs = [[(0, 0)]*K]
to_prove_cubs = [[(0, 0)]*K]
INF = 2 * 10**9

def insct(u, v):
    for k in range(K):
        if u[k][0] > v[k][1]:
            return False
        if u[k][1] < v[k][0]:
            return False
    return True

for _ in range(n):
    ls = [int(x) for x in input().split()]
    hs = [int(x) for x in input().split()]
    proving_cubs.append([(0, x) for x in hs])
    to_prove_cubs.append([(ls[i], hs[i]) for i in range(K)])

for i in range(n+1):
    for j in range(n+1):
        if i == j:
            continue
        if insct(proving_cubs[i], to_prove_cubs[j]):
            #print(f'{i} can prove {j}')
            adjList[i].append(j)

vis = set()
def dfs(u):
    if u in vis:
        return 0
    vis.add(u)
    sm = 1
    for v in adjList[u]:
        if v not in vis:
            sm += dfs(v)
    return sm

print(dfs(0) - 1)
