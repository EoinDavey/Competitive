input()
xs = map(int,raw_input().split())
xs = sorted(xs)
out = []
l = 0
r = len(xs)-1
while(l < r):
    out.append(xs[l])
    out.append(xs[r])
    l+=1
    r-=1
if(l==r):
    out.append(xs[l])
print " ".join(map(str,out))
