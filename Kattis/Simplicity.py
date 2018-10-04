cnt = {}
s = raw_input()
for c in s:
    if c in cnt:
        cnt[c]+=1
    else:
        cnt[c]=1

l = sorted(cnt.items(), key=lambda (a,b): (b,a))
o = 0
while(len(l) > 2):
    o+=l[0][1]
    l = l[1:]
print o
