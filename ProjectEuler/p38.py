def build(i,l):
    m = map(lambda x: x*i,l)
    out = ""
    for n in m:
        out+=str(n)
    return out

def check(i,l):
    m = build(i,l)
    dig = [False]*10
    for n in m:
        if dig[ord(n)-ord('0')]:
            return False
        dig[ord(n)-ord('0')] = True
    return all(dig[1:]) and not dig[0]

for i in range(1,10000):
    ln = len(str(i))
    if check(i, [x for x in range(1,9/ln + 1)]):
        print i, build(i,[x for x in range(1, 9/ln + 1)])
