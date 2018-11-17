import sys
n = input()
a = map(int, list(raw_input()))
sm = sum(a)
if sm == 0:
    print "YES"
    sys.exit(0)
if sm == 1:
    print "NO"
    sys.exit(0)

def check(k):
    sm = 0
    for j in a:
        if sm + j > k:
            return False
        sm += j
        if sm == k:
            sm = 0
    return sm==0

if any(map(lambda x: check(x), filter(lambda x: sm%x==0, range(1,sm)))):
    print "YES"
else:
    print "NO"
