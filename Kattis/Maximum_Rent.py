a,b = map(int,raw_input().split())
m,s = map(int,raw_input().split())

xlim = max(1,s-m)
ylim = 1

if a > b:
    y = ylim
    x = m-y
    print a*x + b*y
else:
    x = xlim
    y = m-x
    print a*x + b*y
