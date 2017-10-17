N = input()
tws = sorted(map(int,raw_input().split()),reverse=True)

mn = N
for i in xrange(N):
    mn = min(mn, i+tws[i])
print mn
