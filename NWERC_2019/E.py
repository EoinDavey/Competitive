def read(x):
    return int(x.replace('.',''))*100

ts = [read(x) for x in input().split()]
tgt = read(input())

def valid(tm):
    nts = ts + [tm]
    nts.sort()
    return sum(nts[1:4]) <= 3*tgt

if valid(10**100):
    print("infinite")
elif not valid(0):
    print("impossible")
else:
    L = 0
    R = 200001
    while L < R:
        md = (L + R + 1)//2
        if valid(md):
            L = md
        else:
            R = md - 1
    print("%.2f" % (L / 10000))
