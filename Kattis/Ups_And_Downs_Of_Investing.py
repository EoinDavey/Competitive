s, n, m = map(int, raw_input().split())
a = []
while len(a) < s:
    a += map(int, raw_input().split())
incr = [0]*s
incl = [0]*s
decr = [0]*s
decl = [0]*s

for i in xrange(s):
    if i > 0 and a[i] > a[i-1]:
        incl[i] = incl[i-1]+1
    else:
        incl[i] = 1

    if i > 0 and a[i] < a[i-1]:
        decl[i] = decl[i-1]+1
    else:
        decl[i] = 1

for i in xrange(s-1, -1, -1):
    if i < s-1 and a[i] < a[i+1]:
        incr[i] = incr[i+1]+1
    else:
        incr[i] = 1

    if i < s-1 and a[i] > a[i+1]:
        decr[i] = decr[i+1]+1
    else:
        decr[i] = 1

pks = vals = 0
for i in xrange(s):
    if incl[i] >= n and decr[i]>=n:
        pks += 1
    if incr[i] >= m and decl[i]>=m:
        vals += 1

print pks, vals
