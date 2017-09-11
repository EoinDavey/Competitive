import math
while(True):
    [D,V] = map(int,raw_input().split())
    if D==0 and V==0:
        break
    print "%.7f" % (pow(D**3 - (6.0/math.pi)*V, 1.0/3))
