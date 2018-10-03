A,B = raw_input().split()
fstA = {}
fstB = {}
def cross(i,j):
    brd = [['.']*len(A) for _ in xrange(len(B))]
    for k,a in enumerate(A):
        brd[j][k] = a
    for k,b in enumerate(B):
        brd[k][i] = b
    return "\n".join(map(lambda x:"".join(x),brd))
for i,a in enumerate(A):
    if a not in fstA:
        fstA[a]=i
for i,a in enumerate(B):
    if a not in fstB:
        fstB[a]=i
for c in A:
    if c in fstB:
        print cross(fstA[c], fstB[c])
        break
