n = int(input())
vs = [int(x) for x in input().split()]

brk = 0
for i in range(1, n):
    if vs[i] < vs[i-1]:
        brk = i
        break

s = brk
e = brk
while s > 0 and vs[s-1] >= vs[s]:
    s -= 1

while e < n - 1 and vs[e+1] <= vs[e]:
    e += 1

ns = vs[:s] + sorted(vs[s:e+1]) + vs[e+1:]
if ns == sorted(vs):
    print(s+1, e+1)
else:
    print("impossible")
