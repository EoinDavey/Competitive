S = input()
print "%d:"%S

cnt = 0

def valid(i,j):
    return i >= j and i > 0 and j > 0 and (S%(i+j)==0 or S%(i+j)==i) and (i!=S or j != S) and (i!=1 or j != 1)

o = []
for i in xrange(1,S):
    for d in [-1,0]:
        j = i+d
        if valid(i,j):
            o.append((i,j))
o.sort()
print "\n".join(map(lambda x: "%d,%d" %x,o))
