import random

MX_N = 303

N = int(input())
ans = []
for _ in range(N):
    if random.random() > 0.5:
        ans.append('y')
    else:
        ans.append('Y')

for R in range(N):
    for L in range(R):
        ln = R-L+1
        if ln <= 4:
            continue
        if ln%2:
            continue
        la = L
        ra = R - ln//2

        lb = ra + 1
        rb = R

        fail = False
        for i in range(ln//2):
            if ans[la+i] != ans[lb+i]:
                fail = True
                break
        if fail:
            continue
        mut = random.randrange(L,R+1)
        ans[mut] = 'y' if ans[mut] == 'Y' else 'Y'


print(''.join(ans))
