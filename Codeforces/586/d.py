from collections import Counter

n = int(input())
bs = [int(x) for x in input().split()]

ls = [0]*n
for i in range(n):
    b = bs[i]
    while b % 2 == 0:
        ls[i] += 1
        b //= 2

c = Counter(ls)
mst = c.most_common(1)[0]
print(n-mst[1])
for i in range(n):
    if ls[i] != mst[0]:
        print(bs[i])
