n, k = *map(int,input().split()),
a = [int(x) for x in input().split()]

jmps = [b - a for (a, b) in zip(a, a[1:n])]
jmps.sort(reverse=True)
print(a[-1] - a[0] - sum(jmps[:(k-1)]))
