import math
def is_prime(x):
    for i in xrange(2,int(math.floor(math.sqrt(x)))):
        if x%i==0:
            return False
    return True
while True:
    p, a = map(int, raw_input().split())
    if not(p or a):
        break
    if is_prime(p):
        print "no"
    elif pow(a,p,p) == a:
        print "yes"
    else:
        print "no"
