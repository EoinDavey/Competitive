[n,h,w] = map(int,raw_input().split())
l = h**2 + w**2
for _ in range(n):
    x = int(raw_input())
    if x**2 <= l:
        print "DA"
    else:
        print "NE"
