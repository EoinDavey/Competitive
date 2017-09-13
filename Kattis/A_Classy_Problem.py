T = int(raw_input())

def rd():
    s = raw_input().split()
    cls = s[1].split("-")
    t = ""
    for c in cls[::-1]:
        if c=='upper':
            t+='1'
        elif c=='middle':
            t+='2'
        else:
            t+='3'
    return (t,s[0][:-1])

for _ in xrange(T):
    N = int(raw_input())
    nms = [rd() for _ in range(N)]
    mxl = max(map(lambda x:len(x[0]),nms))
    nms = map(lambda (b,a): ("".join(list(b)+["2"]*(mxl-len(b))),a),nms)
    nms = sorted(nms)
    nms = map(lambda x:x[1],nms)
    print "\n".join(nms)
    print "".join(['=']*30)
