n, m, d = map(int, raw_input().split())
tot = []
a = map(int, raw_input().split())
for i in xrange(n):
    tot.append((a[i], 0, i))
    tot.append((a[i]+d, 1, i))

tot.sort()
cnt = 0
mx = 0

ans = [0]*n
avail = range(n, 0, -1)
for (_, b, ind) in tot:
    if b:
        avail.append(ans[ind])
        cnt-=1
    else:
        ans[ind] = avail[-1]
        avail.pop()
        cnt+=1
    mx = max(mx, cnt)

print mx
print ' '.join(map(str, ans))
