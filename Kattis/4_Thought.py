ops = ['+','/','-','*']

def run(n):
    for a in ops:
        for b in ops:
            for c in ops:
                if eval("4 %s 4 %s 4 %s 4" % (a,b,c)) == n:
                    print "4 %s 4 %s 4 %s 4 = %s" % (a,b,c,n)
                    return True
for _ in xrange(input()):
    if not run(input()):
        print "no solution"
