xs = [input() for _ in range(9)]
l = len(xs)

ans = []
for i in xrange(l):
    for j in xrange(i+1,l):
        v = sum(filter(lambda x: x!=xs[i] and x!=xs[j],xs))
        if v== 100:
            ans = filter(lambda x: x!=xs[i] and x!=xs[j],xs)
print "\n".join(map(str,ans))
