import sys
def astx(i,l):
    return (i - (l%i))%i

def slve(s):
    for i in xrange(1,6):
        if len(s) > 20*i:
            continue
        a = astx(i, len(s))

        lnr = (len(s)+(i-1))/i
        print i, lnr

        rs = []
        k = 0
        for j in xrange(i):
            o=""
            if a:
                o+="*"
                a-=1
            while len(o) < lnr:
                o+=s[k]
                k+=1
            rs.append(o)
        print '\n'.join(rs)
        return

s = raw_input()
slve(s)
