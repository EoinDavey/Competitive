def find(L,R,x1,y1,x2,y2,even):
    lengthX = x2-x1+1
    lengthY = y2-y1+1
    if targetX >= x1 and targetX <= x2 and targetY >= y1 and targetY <= y2:
        diffx = targetX - x1
        diffy = targetY - y1
        if even:
            return L+diffx*lengthY + diffy
        else:
            return L+diffy*lengthX + diffx
    totalN = R+1
    if(even):
        return find(R+1,R+totalN,0,x1*2 if x1 > 0 else 1,x2,y2*2+1,not even)
    else:
        return find(R+1,R+totalN,y1,x1,y2,y2,not even)

for _ in xrange(input()):
    targetX,targetY = map(int,raw_input().split())
    print find(0,0,0,0,0,0,True)
