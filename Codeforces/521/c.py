n = input()
a = map(int, raw_input().split())
sm = sum(a)

mxl = [0]*n
mxr = [0]*n
for i in xrange(1, n):
    mxl[i] = max(mxl[i-1], a[i-1])
for i in xrange(n-2, -1, -1):
    mxr[i] = max(mxr[i+1], a[i+1])
cnt = 0
ans = []
for i in xrange(n):
    mxar = max(mxl[i],mxr[i])
    if sm - a[i] == 2*mxar:
        cnt+=1
        ans.append(i+1)
print cnt
print ' '.join(map(str, ans))
