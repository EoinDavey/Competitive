d, n = map(int, raw_input().split())
m = input()
for _ in xrange(m):
    x,y = map(int, raw_input().split())
    #f(x) = |x-n|
    #g(x) = -|x-(n-d)| + d
    if y >= abs(x-n) and y <= -abs(x-(d-n)) + d:
        print "YES"
    else:
        print "NO"
