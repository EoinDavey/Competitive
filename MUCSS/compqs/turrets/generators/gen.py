import sys
from random import uniform, randint
from math import pi, sin, cos
from collections import defaultdict

if len(sys.argv) < 2 :
    sys.exit(1)

TOT = int(sys.argv[1])
R = randint(10, 100)
print(TOT, R)
perm = pi*R
for _ in range(TOT):
    angle = uniform(pi, 0)
    x = R*cos(angle)
    y = R*sin(angle)
    r = uniform(perm/(TOT*2*pi), 2*(perm/(TOT*pi)))
    print("%.6f %.6f %.6f" % (x, y, r))
