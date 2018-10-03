def execute(inst):
    x,y=0,0
    dx,dy = (0,1)
    for i in inst:
        if i=="Forward":
            x,y = x+dx,y+dy
        elif i=="Left":
            dx,dy = -dy,dx
        else:
            dx,dy = dy,-dx
    return x,y

x,y=map(int,raw_input().split())
n = input()
ls = [raw_input() for _ in xrange(n)]
b = False
for i in xrange(n):
    for m in ["Forward","Right","Left"]:
        if execute(ls[:i]+[m]+ls[i+1:])==(x,y):
            print i+1,m
            b=True
            break
    if b:
        break
