xs = map(int, raw_input().split())
xs.sort()
a,b,c = xs
if a + b > c:
    print 0
else:
    print (c+1) - (a+b)
