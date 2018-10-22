n, r = map(int, raw_input().split())
a = map(int, raw_input().split())
ones = list(filter(lambda x: a[x]==1, xrange(n)))[::-1]
cov = [False]*n

b = False
cnt = 0
for i in xrange(n):
    if cov[i]:
        continue
    while len(ones) > 1 and ones[-2] - i < r:
        ones.pop()
    if len(ones) >= 1 and ones[-1] -i <r:
        cnt+=1
        for j in xrange(ones[-1]-r+1, ones[-1]+r):
            if j >=0 and j < n:
                cov[j] = True
        ones.pop()
    else:
        b=True
        break

if b:
    print -1
else:
    print cnt
