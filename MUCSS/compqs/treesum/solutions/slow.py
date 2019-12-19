N = int(input())

ps = [-1] + [int(x) for x in input().split()]

vals = [0]*N

Q = int(input())

for _ in range(Q):
    ns = [int(x) for x in input().split()]
    if ns[0] == 1:
        u, v = ns[1:]
        while True:
            vals[u] += v
            if ps[u] == -1:
                break
            u = ps[u]
    else:
        u = ns[1]
        print(vals[u])
