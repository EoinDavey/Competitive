n, I = *map(int,input().split()),
a = [int(x) for x in input().split()]
a.sort()

tgtbpn = (I*8)//n
mxvals = 1<<tgtbpn

c = []
i = 0
while i < len(a):
    j = i
    cnt = 0
    while j < len(a) and a[j] == a[i]:
        cnt+=1
        j+=1
    c.append(cnt)
    i = j

sm = 0
mn = n
for i in range(len(c)):
    sm += c[i]
    if i-mxvals >= 0:
        sm -= c[i-mxvals]
    mn = min(mn, n-sm)
print(mn)
