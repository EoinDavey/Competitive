import sys
n = input()
xs = map(int, raw_input().split())

if n==1:
    print xs[0]+1
    sys.exit(0)

ls = [0]*n

for i in xrange(n):
    ls[i] = xs[i] - (ls[i-1] if i else 0)

lw = ls[::2]
up = ls[1::2]

l = min(lw)
u = max(0,-min(up))

print max(0, l-u+1)
