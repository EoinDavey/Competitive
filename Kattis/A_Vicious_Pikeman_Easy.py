MOD_7 = 1000000007

[N,T] = map(int,raw_input().split())
a = [0]*N
[A,B,C,t0] = map(int,raw_input().split())
a[0]=t0
for i in range(1,N):
    a[i] = ((A*a[i-1] + B) % C) + 1
a.sort()
print a
sm = 0
cnt=0
tm = 0
for i in range(N):
    if sm+a[i] <= T:
        tm+=a[i]
        sm+=tm
        cnt+=1
    else:
        break
print "%d %d" %(cnt,(sm%MOD_7))
