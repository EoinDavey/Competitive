mx = 0
for p in range(3,1001):
    cnt = 0
    for a in range(1,p):
        for b in range(a,p-a):
            c = p - a - b
            if a**2 + b**2 == c**2:
                cnt+=1
    if cnt > mx:
        mx = cnt
        print p
