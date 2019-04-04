og = map(int, raw_input().split())

g = og[:]
cnt = 0
s = {}
while 1:
    i = max(xrange(len(og)),key=lambda x: g[x])
    v = g[i]
    g[i]-=v
    i=(i+1)%len(g)
    while v:
        g[i]+=1
        v-=1
        i=(i+1)%len(g)
    cnt+=1

    if tuple(g) in s:
        print cnt - s[tuple(g)]
        break
    s[tuple(g)] = cnt
