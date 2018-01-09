X,Y = map(int,raw_input().split())
E = X*2 + Y*3
if E%2==0:
    print "possible"
else:
    print "impossible"
