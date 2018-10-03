def val(x):
    o = ord(x)
    if o >= ord('0') and o <= ord('9'):
        return o-ord('0')
    return 10 + ord(x)-ord('a')

def bConv(s,b):
    o = 0
    for c in s:
        o*=b
        o+=val(c)
    return o

fMap = {
        '+': lambda x,y: x+y,
        '-': lambda x,y: x-y,
        '*': lambda x,y: x*y,
        '/': lambda x,y: -1 if x%y!= 0 else x/y,
}

def check(s,r):
    if (r > 1 and any(map(lambda x: val(x) >= r,s[0]+s[2]+s[4]))) or (r == 1 and any(map(lambda x: x!='1', s[0]+s[2]+s[4]))):
        return False
    a = s[0]
    op = fMap[s[1]]
    b = s[2]
    c = s[4]
    return op(bConv(a,r),bConv(b,r)) == bConv(c,r)

def rVal(x):
    if x >= 0 and x <= 9:
        return chr(ord('0')+x)
    if x==36:
        return '0'
    return chr(ord('a')+x-10)

for _ in xrange(input()):
    c = raw_input().split()
    ans = []
    for i in xrange(1,37):
        if check(c,i):
            ans.append(rVal(i))
    if len(ans)==0:
        print "invalid"
    else:
        print "".join(ans)
