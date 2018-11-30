import math

n, m = map(int, raw_input().split())
mn = max(0, n-2*m)

ans = n
for i in xrange(n, -1, -1):
    if (i*(i-1))/2 < m:
        break
    ans = i

print mn, n-ans
