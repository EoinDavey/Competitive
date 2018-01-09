import math
r = (2*math.pi/28.0)*2.0

def ind(x):
    if x >= 'A' and x <= 'Z':
        return ord(x) - ord('A')
    return 26 if x==" " else 27

def d(x,y):
    return min(abs(ind(x)-ind(y)),28-abs(ind(x)-ind(y)))

def time(x,y):
    return d(x,y) * r + 1

for _ in xrange(input()):
    tm = 1.0
    s = raw_input()
    st = s[0]
    s = s[1:]
    for x in s:
        tm+=time(st,x)
        st=x
    print tm
