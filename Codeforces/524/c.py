def whiterc(x,y):
    f = y/2
    c = (y+1)/2
    ods = (x+1)/2
    evs = x-ods
    return ods*c + evs*f

def whitesin(x1,y1,x2,y2):
    sm = whiterc(x2,y2)
    if x1 > 1 and y1 > 1:
        sm += whiterc(x1-1, y1-1)
    if x1 > 1:
        sm -= whiterc(x1-1,y2)
    if y1 > 1:
        sm -= whiterc(x2,y1-1)
    return sm

def blacksin(x1,y1,x2,y2):
    return (x2-x1+1)*(y2-y1+1) - whitesin(x1,y1,x2,y2)

def inside(p,q,x1,y1,x2,y2):
    return p >= x1 and p <= x2 and q >= y1 and q <= y2

def overlap(x11, y11, x21, y21, x12, y12, x22, y22):

    if x11 > x22 or y11 > y22 or x12 > x21 or y12 > y21:
        return None

    return ((max(x11,x12), max(y11,y12)),(min(x21,x22), min(y21,y22)))


for _ in xrange(input()):
    n, m = map(int, raw_input().split())

    wx1,wy1,wx2,wy2 = map(int, raw_input().split())
    bx1,by1,bx2,by2 = map(int, raw_input().split())

    p = overlap(wx1,wy1,wx2,wy2,bx1,by1,bx2,by2)

    if p == None:
        blacks = blacksin(1,1,m,n) - blacksin(wx1,wy1,wx2,wy2) - blacksin(bx1,by1,bx2,by2)
        blacks += (bx2-bx1+1)*(by2-by1+1)
        whites = (n*m) - blacks
        print whites, blacks
    else:
        (px1,py1),(px2,py2) = p

        blacks = blacksin(1,1,m,n) - blacksin(wx1,wy1,wx2,wy2) - blacksin(bx1,by1,bx2,by2)
        blacks += blacksin(px1,py1,px2,py2)
        blacks += (bx2-bx1+1)*(by2-by1+1)
        whites = (n*m) - blacks
        print whites, blacks
