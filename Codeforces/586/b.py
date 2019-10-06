import math
n = int(input())
a = [[int(x) for x in input().split()] for _ in range(n)]

a12 = (a[0][1] * a[0][2])/a[1][2]
a1 = int(math.sqrt(a12))
a = [a1] + [x // a1 for x in a[0][1:]]
print(*a)
