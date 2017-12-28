L,X = map(int,raw_input().split())
sm = 0
cnt = 0
for _ in xrange(X):
    w,n = raw_input().split()
    n=int(n)
    if w=="enter":
        if sm+n > L:
            cnt+=1
        else:
            sm+=n
    else:
        sm-=n
print cnt
