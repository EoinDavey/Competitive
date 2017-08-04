def col(x):
    while(1):
        if x==1:
            return
        if x%2==0:
            yield x/2
            x/=2
        else:
            yield 3*x + 1
            x = 3*x + 1

while(True):
    [a,b] = map(int,raw_input().split())
    if a==0 and b==0:
        break
    ap = col(a)
    bp = col(b)

    apath = [a]
    bpath = [b]

    for x in ap:
        apath.append(x)
    for x in bp:
        bpath.append(x)
    al = len(apath)
    bl = len(bpath)

    k = 1
    cnt = 0
    for i in range(min(bl,al)):
        if apath[al-i-1]!=bpath[bl-i-1]:
            break
        k = apath[al-i-1]
        cnt+=1
    print "%d needs %d steps, %d needs %d steps, they meet at %d" %(a,al-cnt,b,bl-cnt,k)
