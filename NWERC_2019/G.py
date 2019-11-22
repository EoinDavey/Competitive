import sys
N, K = [int(x) for x in input().split()]
ss = [float(x) for x in input().split()]
ss.reverse()

if N == 1:
    print(100)
    sys.exit(0)

if K == 1:
    print(' '.join([str(100/N)]*N))
    sys.exit(0)

LIM = 505
ncrmem = [[-1]*LIM for _ in range(LIM)]

def ncr(n, r):
    if n == 0:
        return r == 0
    if r == 0:
        return 1
    if ncrmem[n][r] != -1:
        return ncrmem[n][r]
    ncrmem[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r)
    return ncrmem[n][r]

probs = [0]*N
for st in range(N):
    tot = 0
    sm = 0
    for l in range(2, N+1):
        if N - l < K - 2:
            break
        prob = ncr(N - l, K - 2)/ncr(N, K)
        sm += ss[(st + l-2) % len(ss)]
        tot += prob*sm
    probs[st] = tot

probs.reverse()
print(' '.join(map(lambda x: '%.9f' % x, probs)))
