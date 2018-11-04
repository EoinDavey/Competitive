cap = 10
cnt = 0

def test(xs):
    if xs[0] != 9:
        return False
    return all(map(lambda i: xs[i] <= max(xs[i-1], xs[i+1]), xrange(1,len(xs)-1))) and xs[1] >= xs[0] and xs[len(xs)-2] >= xs[len(xs)-1]

for i in xrange(cap):
    for j in xrange(cap):
        for k in xrange(cap):
            for l in xrange(cap):
                for m in xrange(cap):
                    if test([i,j, k, l, m]):
                        print i,j,k,l,m
                        cnt+=1
print cnt
