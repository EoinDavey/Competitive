n = input()
m = input()

a = [input() for _ in xrange(n)]

mx = max(a) + m

while m:
    ind = min(range(n), key=lambda x: a[x])
    a[ind]+=1
    m-=1
mn = max(a)
print mn, mx
