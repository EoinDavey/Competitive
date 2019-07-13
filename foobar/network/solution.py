from collections import deque, defaultdict
INF = 10**10

def solution(entrances, exits, path):
    N = len(path)
    S = N
    T = N+1
    adjLists = [[] for _ in xrange(N+2)]
    res = [[0]*(N+2) for _ in xrange(N+2)]
    for x in entrances:
        adjLists[S].append(x)
        res[S][x] = INF
    for x in exits:
        adjLists[x].append(T)
        res[x][T] = INF
    for i in xrange(N):
        for j in xrange(N):
            if path[i][j]:
                adjLists[i].append(j)
                res[i][j] = path[i][j]

    def aug(u, minE):
        if u == S:
            return minE
        f = aug(p[u], min(minE, res[p[u]][u]))
        res[p[u]][u] -= f
        res[u][p[u]] += f
        return f

    mf = 0
    p = defaultdict(lambda: -1)
    while True:
        q = deque([S])
        vis = set([S])
        while q:
            u = q.popleft()
            if u == T:
                break
            for v in adjLists[u]:
                if res[u][v] and v not in vis:
                    vis.add(v)
                    q.append(v)
                    p[v] = u
        if T not in vis:
            break
        mf += aug(T, INF)
    return mf
