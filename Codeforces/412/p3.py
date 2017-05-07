import math
x = 0
y = 0
d = 0

def euclid(a, b):
    global x, y, d
    if (b==0):
        x = 1
        y = 0
        d = a
        return
    euclid(b, a % b)
    x1 = y
    y1 = x - (a/b) * y
    x = x1
    y = y1

T = int(input())
for _ in range(0,T):
    [X,Y,P,Q] = map(int,raw_input().split())
    if(P==Q and X!=Y):
        print -1
        continue
    if(X==0 and Y==0):
        print "%d" % Q
        continue
    if(P==0):
        if(X==0):
            print 0
        else:
            print -1
        continue
    euclid(Q,-P)
    c = P*Y - X*Q
    x*=(c/d)
    y*=(c/d)
    print "%d %d %d" % (x,y,c)
    print x*Q - y*P
    d=1
    ns = [x*(1.0/float(-P))-1, y*(1.0/float(-Q))-1, (x-y)/float(Q-P)-1, x*(1.0/float(-P)), y*(1.0/float(-Q)), (x-y)/float(Q-P)]
    print ns
    print [(1.0/float(-P)), (1.0/float(-Q)), (x-y)/float(Q-P)]
    for i in ns:
        n = math.ceil(i)
        xn = x + (P)*n
        yn = y + (Q)*n
        print xn*Q - yn*P
        if(yn >= xn and xn >= 0):
            print "%f %f" % (xn,yn)
            print "%.0f" % yn
            break
