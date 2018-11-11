cvt = [
        (1000, 'M'),
        (900, 'CM'),
        (500, 'D'),
        (400, 'CD'),
        (100, 'C'),
        (90, 'XC'),
        (50, 'L'),
        (40, 'XL'),
        (10, 'X'),
        (9, 'IX'),
        (5, 'V'),
        (4, 'IV'),
        (1, 'I'),
]

R2Imp = {}
I2Rmp = {}
for k, v in cvt:
    R2Imp[v] = k
    I2Rmp[k] = v

def ItoR(x):
    o = []
    for k, v in cvt:
        while x >= k:
            o.append(v)
            x-=k
    return ''.join(o)

def RtoI(s):
    o = 0
    i = 0
    while i < len(s):
        if i < len(s)-1 and R2Imp[s[i+1]] > R2Imp[s[i]]:
            o += R2Imp[s[i+1]] - R2Imp[s[i]]
            i+=1
        else:
            o += R2Imp[s[i]]
        i+=1
    return o

nms = map(ItoR, xrange(1, 1000))
nms.append('')
nms.sort()
indMap = {}
for i in xrange(len(nms)):
    if len(nms[i]) == 0 or nms[i][0] < 'V':
        indMap[nms[i]] = i
    if i > 0 and len(nms[-i]) > 0 and nms[-i][0] >= 'V':
        indMap[nms[-i]] = -i

def slv(x):
    mcnt = 0
    while mcnt < len(x) and x[mcnt]=='M':
        mcnt+=1
    rm = x[mcnt:]
    if len(rm) == 0 or rm[0] < 'V':
        return mcnt*946 + indMap[rm]
    return mcnt*(946-1000) + indMap[rm]

n = input()
for _ in xrange(n):
    print slv(ItoR(input()))
