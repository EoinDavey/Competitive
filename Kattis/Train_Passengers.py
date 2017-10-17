C, N = map(int,raw_input().split())

sz = 0
fail = False
for n in range(N):
    o,i,w = map(int,raw_input().split())
    sz-=o;
    if sz<0:
        fail=True
    sz+=i
    if sz > C:
        fail = True
    if w > 0 and sz < C:
        fail = True
    if n==N-1 and (w > 0 or sz > 0):
        fail = True

if fail:
    print "impossible"
else:
    print "possible"
