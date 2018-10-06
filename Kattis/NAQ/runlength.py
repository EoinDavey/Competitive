def encrypt(s):
    o = ""
    r = 1
    p = s[0]
    for c in s[1:]:
        if c == p:
            r+=1
        else:
            o+="%s%d"%(p,r)
            r = 1
            p = c
    o+="%s%d"%(p,r)
    return o

def decrypt(s):
    o=""
    for i in xrange(0,len(s),2):
        o += "".join([s[i]]*int(s[i+1]))
    return o

b = raw_input().split()
print encrypt(b[1]) if b[0]=="E" else decrypt(b[1])
