xs = []
ys = []
for _ in range(3):
    [x,y] = map(int,raw_input().split())
    xs.append(x)
    ys.append(y)
xs.sort()
ys.sort()
if xs[0]==xs[1]:
    ax = xs[2]
else:
    ax = xs[0]

if ys[0]==ys[1]:
    ay = ys[2]
else:
    ay = ys[0]

print ax, ay
