def rep(x):
    if x=='-':
        return '|'
    if x=='|':
        return '-'
    return x

def rotate(lines):
    mxlen = max(map(len,lines))
    lines = map(lambda x: x+"".join([" "]*(mxlen-len(x))),lines)
    rot = map(lambda x: map(rep,list(x)[::-1]),zip(*lines))
    print "\n".join(map(lambda x:"".join(x).rstrip(),rot))

b = False
while 1:
    n = input()
    if n==0:
        break
    if b:
        print ""
    b=True
    lines = [raw_input() for _ in xrange(n)]
    rotate(lines)
