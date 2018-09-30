def tri(n):
    return (n*(n+1))/2

T = input()
for _ in xrange(T):
    a,b = map(int,raw_input().split())
    print tri(a+b)+1 + b
