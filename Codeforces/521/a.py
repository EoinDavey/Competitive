def solve(a,b,k):
    diff = a-b
    if k%2 == 0:
        return k/2 * diff
    return k/2*diff + a

for _ in xrange(input()):
    a,b,k = map(int, raw_input().split())
    print solve(a,b,k)
