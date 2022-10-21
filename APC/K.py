a, b, c = [int(x) for x in input().split()]
w = input()
p = input()

def buildRuns(p, pchar):
    if p.count(pchar) == 0:
        return 0
    gaps = []
    pc = [-2]*len(p)
    pc[0] = -1 if p[0] != pchar else 0
    for i in range(1, len(p)):
        if p[i-1] == pchar:
            pc[i] = i-1
        else:
            pc[i] = pc[i-1]

    for i in range(1, len(p)):
        if p[i] != pchar:
            continue
        if pc[i] != i-1:
            gaps.append((pc[i], i, i-pc[i]-1))
    #print(pc)
    #print(gaps)
    cst = 0
    for (u, v, l) in gaps:
        if u == -1:
            continue
        cont = a * l
        stp = 2 * c
        #if cont < stp:
        #    print(f"Go behind: {u}->{v}")
        #else:
        #    print(f"Stop and restart: {u}->{v}")
        cst += min(cont, stp)
    cst += 2*c # Original start and final stop
    cst += b * p.count(pchar)
    return cst

for x in w:
    print(buildRuns(p, x))
