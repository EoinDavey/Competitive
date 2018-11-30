n = input()
a = map(int, raw_input().split())
mx = 0
rn = 0
pv = 10**18
for x in a:
    if x <= 2*pv:
        rn+=1
    else:
        mx = max(mx, rn)
        rn=1
    pv = x

mx = max(mx, rn)
print mx
