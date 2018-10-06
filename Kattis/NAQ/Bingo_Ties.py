from itertools import combinations
n = input()
boards = []
winStrings = set()

xMap = {}

def add(x,r):
    if x not in xMap:
        xMap[x] = [r]
    else:
        xMap[x].append(r)

for i in xrange(n):
    if i:
        raw_input()
    b = [set(raw_input().split()) for _ in xrange(5)]
    boards.append(b)
    for r in b:
        winStrings.add(",".join(sorted(r)))
        for x in r:
            add(x,(i,r))

def solve(a,b):
    for ra in boards[a]:
        for rb in boards[b]:
            xs = ra.intersection(rb)
            for x in xs:
                s = ra.union(rb).difference(set([x]))
                suc = True
                for c in combinations(s,5):
                    if ",".join(sorted(c)) in winStrings:
                        suc = False
                        break
                if suc:
                    return True
    return False

b = False
for i in xrange(n):
    if b:
        break
    for j in xrange(i+1,n):
        if solve(i,j):
            b = True
            print i+1,j+1
            break
if not b:
    print "no ties"
