import math

[M,N,t] = map(int,raw_input().split())
def fac(n):
    o = 1
    for i in range(1,n+1):
        o*=i
        if o > M:
            return False
    return True

def exp2(n):
    o = 1
    for _ in range(1,n+1):
        o*=2
        if o > M:
            return False
    return True

def quad(n):
    o = 1
    for _ in range(4):
        o*=n
        if o > M:
            return False
    return True


def cub(n):
    o = 1
    for _ in range(3):
        o*=n
        if o > M:
            return False
    return True

def sq(n):
    o = 1
    for _ in range(2):
        o*=n
        if o > M:
            return False
    return True

def nlogn(n):
    o = (n*1.0) * math.log(n,2)
    if o > M:
        return False
    return True

def lin(n):
    if n > M:
        return False
    return True

fs = [fac,exp2,quad,cub,sq,nlogn,lin]

if fs[t-1](N):
    print "AC"
else:
    print "TLE"
