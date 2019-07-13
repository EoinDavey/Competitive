from itertools import permutations


def getcycs(perm):
    vis = set()
    def v(x):
        if x in vis:
            return 0
        vis.add(x)
        return 1 + v(perm[x])
    o = []
    for x in perm:
        a = v(x)
        if a:
            o.append(a)
    return sorted(o)

cnt = 0
for perm in permutations(range(6)):
    c = getcycs(perm)
    if c == [1,2,3]:
        cnt+=1
print cnt
