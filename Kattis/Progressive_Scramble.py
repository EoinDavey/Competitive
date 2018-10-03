def val(x):
    if x==" ":
        return 0
    return ord(x)-ord('a')+1

def fVal(x):
    if x:
        return chr(ord('a')+x-1)
    return " "

def encrypt(s):
    o=""
    u = 0
    for c in s:
        ui = val(c) + u
        u=ui
        o+=fVal(ui%27)
    return o

def decrypt(ins):
    o = ""
    u = 0
    s = map(val,ins)
    for c in s:
        rVal = (c-u)%27
        u+=rVal
        o+=fVal(rVal)
    return o

for _ in xrange(input()):
    b = raw_input()
    if b[0]=="e":
        print encrypt(b[2:])
    else:
        print decrypt(b[2:])
