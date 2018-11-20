N = input()
M = input()
ins = map(int, raw_input().split())
outs = map(int, raw_input().split())

cnt = {}
for i in ins:
    for j in outs:
        if j > i:
            if j-i in cnt:
                cnt[j-i]+=1
            else:
                cnt[j-i]=1

mx = 0
ans = 0
for k,v in cnt.items():
    if v > mx:
        mx = v
        ans = k
    elif v==mx:
        ans = min(ans, k)
print ans
