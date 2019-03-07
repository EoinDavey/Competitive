m = input()

def tr(x):
    s = 0
    i = 1
    while s < m:
        s += i**x
        i+=1
    if s==m:
        return i
    return 0

suc = False
for x in xrange(2, 65):
    s = tr(x)
    if s:
        print x+1, s-1
        suc=True
        break
if not suc:
    print "impossible"
