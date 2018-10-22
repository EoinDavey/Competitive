import math
import sys
def is_sq(x):
    s = int(math.floor(math.sqrt(x)))
    return s*s == x

def inv(x):
    return (1 + int(math.floor(math.sqrt(1+8*x))))/2

a,b,c,d = map(int, raw_input().split())

zs = inv(a)
os = inv(d)

if not(a or b or c or d):
    print "0"
    sys.exit(0)

if not is_sq(1+8*a) or not is_sq(1+8*d):
    print "impossible"
    sys.exit(0)


def tr(b, c, o, z):
    s = []

    brk = False
    for i in xrange(z+o):
        if z and b >= o:
            b -= o
            s.append('0')
            z-=1
        elif o and c >= z:
            c -= z
            s.append('1')
            o -= 1
        else:
            brk = True

    if brk:
        return False, ""
    else:
        return True, "".join(s)

if a and d:
    g, h = tr(b,c,os,zs)
    if g:
        print h
    else:
        print "impossible"
else:
    g, h = tr(b,c,os,zs)
    if g:
        print h
    else:
        g, h = tr(b,c,0,zs)
        if g:
            print h
        else:
            print "impossible"
    g, h = tr(b,c,os,zs)
    if g:
        print h
    else:
        g, h = tr(b,c,os, 0)
        if g:
            print h
        else:
            print "impossible"
    g, h = tr(b,c,os,zs)
    if g:
        print h
    else:
        g, h = tr(b,c,0,0)
        if g:
            print h
        else:
            print "impossible"
