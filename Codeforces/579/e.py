n = int(input())
a = [int(x) for x in input().split()]
a.sort(reverse=True)

ub = 150002

cnt = 0
for x in a:
    if x + 1 < ub:
        ub = x+1
        cnt+=1
    elif x < ub:
        ub = x
        cnt+=1
    elif x-1 > 0 and x-1 < ub:
        ub = x-1
        cnt+=1
print(cnt)
