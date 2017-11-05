rotperms = [
        [3,1,4,2,17,18,7,8,9,10,11,12,5,6,15,16,21,22,19,20,13,14,23,24],
        [1,2,16,14,7,5,8,6,19,17,11,12,13,9,15,10,3,18,4,20,21,22,23,24],
        [24,2,22,4,1,6,3,8,5,10,7,12,15,13,16,14,17,18,19,20,21,11,23,9]
        ]
rotperms = map(lambda x: map(lambda i: i-1,x),rotperms)

def apperm(inp,i):
    return map(lambda x: inp[rotperms[i][x]],range(len(inp)))

rotperms+= map(lambda x: apperm(apperm(apperm(range(24),x),x),x),[0,1,2])

faces = map(lambda i: range(i,i+4), range(0,22,4))

colours = map(int,raw_input().split())

def chkface(fc, perm):
    return all(map(lambda x: colours[perm[x]] == colours[perm[fc[0]]],fc))

if any(map(lambda perm: all(map(lambda x: chkface(x,perm),faces)),rotperms)):
    print "YES"
else:
    print "NO"
