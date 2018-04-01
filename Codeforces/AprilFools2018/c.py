N = input()
xs = map(int,raw_input().split())

def check():
    for i in xrange(1,N):
        if abs(xs[i]-xs[i-1]) >= 2:
            return False
    return True

def run():
    global xs
    global N
    while(len(xs)>0):
        N = len(xs)
        if(not check()):
            return False
        mx = max(range(N),key=lambda x: xs[x])
        xs = xs[:mx] + xs[mx+1:]
    return True

if run():
    print "YES"
else:
    print "NO"
