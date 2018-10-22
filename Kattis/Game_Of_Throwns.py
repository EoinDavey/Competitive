N, K = map(int, raw_input().split())
coms = raw_input().split()
c = 0
stck = []
undo = False
for com in coms:
    if com=="undo":
        undo=True
        continue
    d = int(com)
    if undo:
        for _ in xrange(d):
            c = (c - stck[-1] + N) % N
            stck.pop()
        undo=False
    else:
        stck.append(d)
        c = (c + d + N) % N
print c
