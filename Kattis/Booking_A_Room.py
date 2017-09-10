[n,r] = map(int,raw_input().split())
rms = [False]*(n+1)

for _ in range(r):
    rms[int(raw_input())]=True

if r < n:
    for i in range(1,n+1):
        if not rms[i]:
            print i
            break
else:
    print "too late"
