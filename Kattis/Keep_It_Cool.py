n, m, s, d = *map(int, input().split()),
cs = list(map(int, input().split()))
perm = list(range(len(cs)))
perm.sort(key=lambda x: cs[x])
hidden = 0
rf = [0]*len(cs)
for i in range(len(cs)):
    gap = d-cs[perm[i]]
    use = min(n, gap)
    n -= use
    rf[perm[i]] = use

    if use:
        hidden += cs[perm[i]]

if sum(cs) - hidden >= m:
    print(' '.join(map(str, rf)))
else:
    print('impossible')
