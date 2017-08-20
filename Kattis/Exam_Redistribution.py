N = int(raw_input())
xs = map(int, raw_input().split())
sm=sum(xs)
mx=max(xs)
if mx > sm-mx:
    print "impossible"
else:
    z = zip(xs,range(1,len(xs)+1))
    z.sort(reverse=True)
    print " ".join(map(lambda (_,y):str(y),z))
