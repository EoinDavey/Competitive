[h,m] = map(int,raw_input().split())
m-=45
if m < 0:
    h-=1
print "%d %d" % (h % 24, m % 60)
