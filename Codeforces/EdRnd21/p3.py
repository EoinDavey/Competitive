[n,w] = map(int,raw_input().split())
a = map(int, raw_input().split())
s = sorted(range(len(a)), key=lambda k: a[k])
out = [0]*n
failed=False
for x in s:
    out[x] = (a[x]+1)/2
    w-=out[x]
    if w<0:
        failed=True

for x in reversed(s):
    if w<=0:
        break
    new = min(w,a[x] - out[x])
    w-=new
    out[x]+=new

if failed:
    print -1
else:
    print " ".join(map(str,out))
