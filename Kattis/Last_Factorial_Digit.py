def solve(x):
    if x >= 5:
        return 0
    return str(reduce(lambda x,y: x*y, xrange(1,x+1)))[-1]

for _ in xrange(input()):
    print solve(input())
