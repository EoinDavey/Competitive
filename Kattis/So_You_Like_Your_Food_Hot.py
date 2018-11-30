def read(x):
    l = map(int, x.split('.'))
    return 100*l[0] + l[1]

p, p1, p2 = map(read, raw_input().split())

x = 0
b = False
while 1:
    if x*p1 > p:
        break
    if (p-x*p1)%p2==0:
        b = True
        print x, (p-x*p1)/p2
    x+=1
if not b:
    print "none"
