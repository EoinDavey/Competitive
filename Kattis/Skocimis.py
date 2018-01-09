xs = map(int,raw_input().split())
mvs = 0
while True:
    gp1 = xs[1]-xs[0]
    gp2 = xs[2]-xs[1]
    if gp1==1 and gp2==1:
        break
    if gp2 > gp1:
        xs[0] = xs[1]+1
    else:
        xs[2] = xs[1]-1
    xs.sort()
    mvs+=1
print mvs
