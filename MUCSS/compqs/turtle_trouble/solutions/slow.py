N = int(input())
ls = [int(x) for x in input().split()]

smtab = [ls[0]]
for i in range(1, N):
    v = smtab[-1] + ls[i]
    smtab.append(v)

mx = 0
for i in range(N):
    for j in range(i):
        mx = max(mx, abs(smtab[i] - (0 if j == 0 else smtab[j-1])))
print(mx)
