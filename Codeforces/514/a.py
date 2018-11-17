n, L, a = map(int, raw_input().split())
cnt = 0
prv = 0
for _ in xrange(n):
    t, l = map(int, raw_input().split())
    cnt+= (t-prv)/a
    prv = t + l
cnt+= (L-prv)/a
print cnt
