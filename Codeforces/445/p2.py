n = input()

d = {}

xs = map(int,raw_input().split())

for i in xrange(n):
    d[xs[i]]=i

mn =  1000000000
ans = 0
for a,b in d.iteritems():
    if b < mn:
        ans = a
        mn = b
print ans
