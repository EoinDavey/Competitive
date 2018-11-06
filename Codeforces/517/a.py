def n(w,h,i):
    sz =  2*((w-4*(i-1))+(h-4*(i-1)))
    if sz >= 4:
        sz-=4
    return sz

w,h,k=map(int,raw_input().split())
cnt = 0
for i in xrange(k):
    cnt+=n(w,h,i+1)
print cnt
