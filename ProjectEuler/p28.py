n = 2
sm = 1
for s in range(1,501):
    sz = s*2
    for t in range(4):
        if t == 0:
            n+= sz-1
        else:
            n+=sz
        sm+=n
    n+=1
print sm
