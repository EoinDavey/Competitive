from itertools import permutations
INF = 10**10

def solution(times, times_limit):
    apdis = [list(x) for x in times]

    bns = len(times)-2

    for k in xrange(len(times)):
        for u in xrange(len(times)):
            for v in xrange(len(times)):
                apdis[u][v] = min(apdis[u][v], apdis[u][k] + apdis[k][v])

    inf = False
    for i in xrange(len(times)):
        if apdis[i][i] < 0:
            inf = True

    if inf:
        return range(bns)

    bst = []

    for st in xrange(2**bns):
        ls = []
        for i in xrange(bns):
            if (st & (1 << i)) != 0:
                ls.append(i+1)
        for route in permutations(ls):
            route = (0,) + route + (len(times) - 1,)
            pv = 0
            tm = 0
            for x in route:
                tm += apdis[pv][x]
                pv = x
            if tm <= times_limit:
                if len(ls) > len(bst) or (len(ls)==len(bst) and ls < bst):
                    bst = ls
    return map(lambda x: x-1, bst)
