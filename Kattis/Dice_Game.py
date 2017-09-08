def solve(ws):
    [a1,b1,a2,b2] = ws
    res = []
    for i in range(a1,b1+1):
        for j in range(a2,b2+1):
            res.append(i+j)
    return (sum(res)*1.0)/(len(res)*1.0)

xs = map(int,raw_input().split())
ys = map(int,raw_input().split())

x= solve(xs)
y= solve(ys)

if x>y:
    print "Gunnar"
elif x==y:
    print "Tie"
else:
    print "Emma"
