def toB(x, base):
    o = ""
    while x:
        o += str(x%base)
        x /= base
    return "".join(reversed(o))

def modAdd(a,b,c):
    return ((a%c) + (b%c) + c) % c
def modMult(a,b,c):
    return ((a%c) * (b%c)) % c

while 1:
    inp = raw_input().split()
    if inp[0]=="0":
        break
    b, p, m = inp
    b = int(b)
    m = int(m, b)
    p = int(p, b)

    print toB(p%m,b)
