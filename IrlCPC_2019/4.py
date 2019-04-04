C, W = map(int, input().split())

s = input().split()
mxLen = max(map(len, s))
fW = mxLen + (4 if mxLen % 2 == 1 else 5)

def pad(s):
    s = ' '.join(s)
    o = "* " + s
    while len(o) < fW-1:
        o+= ' '
    o += '*'
    assert(len(o) == fW)
    return o
top = ' '.join(['*']*((fW+1)//2))
print(top)

o = []
for w in s:
    if len(' '.join(o+[w])) > mxLen:
        print(pad(o))
        o = [w]
    else:
        o.append(w)
if o:
    print(pad(o))

print(top)

