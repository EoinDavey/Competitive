import math

def solve(v0,theta,x1,h1,h2):
    theta *= (math.pi/180.0)
    t = x1/(v0*math.cos(theta))
    y = x1*math.tan(theta) - 0.5*9.81*(t**2)
    if y >= h1 and y <= h2:
        return True
    return False

N = int(raw_input())
for _ in range(N):
    [v0,theta,x1,h1,h2] = map(float,raw_input().split())
    if solve(v0,theta,x1,h1+1.0,h2-1.0):
        print "Safe"
    else:
        print "Not Safe"
