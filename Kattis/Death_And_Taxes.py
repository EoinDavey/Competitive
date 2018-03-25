import sys

v=0
n=0

for line in sys.stdin:
    xs = line.split()
    com = xs[0]
    if com=="buy":
        x = int(xs[1])
        y = int(xs[2])
        v = (n*v + x*y)/(n+x)
        n+=x
    elif com=="sell":
        x = int(xs[1])
        y = int(xs[2])
        n-= x
    elif com=="split":
        x = int(xs[1])
        v/=x
        n*=x
    elif com=="merge":
        x = int(xs[1])
        v*=x
        n//= x
    elif com=="die":
        x = int(xs[1])
        print(n*x - n*0.3*max(0,(x-v)))
