[N,P,Q] = map(int,raw_input().split())
s = ((P+Q)/N)
if s%2==0:
    print "paul"
else:
    print "opponent"
