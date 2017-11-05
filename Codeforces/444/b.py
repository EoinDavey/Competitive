import itertools
n = input()

cbs = [raw_input().split() for _ in range(n)]

pos = set()

for perm in itertools.permutations(range(len(cbs))):
    for a in cbs[perm[0]]:
        pos.add(int("".join([a])))
        if len(cbs) <= 1:
            continue
        for b in cbs[perm[1]]:
            pos.add(int("".join([a,b])))
            if len(cbs) <= 2:
                continue
            for c in cbs[perm[2]]:
                pos.add(int("".join([a,b,c])))
lm = 0
for i in xrange(1,1000):
    if i in pos:
        lm = i
    else:
        break
print lm
