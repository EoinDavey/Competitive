def facs(x):
    o = []
    for i in xrange(1, x+1):
        if x%i==0:
            o.append(i)
    return o

V = input()
fs = facs(V)

mn = 10**18
for a in fs:
    for b in fs:
        if V % (a*b) != 0:
            continue
        c = V/(a*b)
        mn = min(mn, 2*(a*b+a*c+b*c))
print mn
