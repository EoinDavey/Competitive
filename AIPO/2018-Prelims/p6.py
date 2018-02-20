d = {}
st = input()
N = len(st)

m = {'T' : 'A',
    'A':'T',
    'C':'G',
    'G':'C'}

def inv(v):
    return "".join([m[c] for c in v][::-1])

for i in range(N):
    for j in range(i+1,N+1):
        sb = st[i:j]
        if sb in d:
            d[sb].append((i,j-1))
        else:
            d[sb] = [(i,j-1)]

mxlen = 0
f = s = ""
for i in range(N):
    for j in range(i+1,N+1):
        sb = inv(st[i:j])
        if sb not in d:
            continue
        for (b,e) in d[sb]:
            if b > j-1 and len(sb) > mxlen:
                mxlen = len(sb)
                f = st[i:j]
                s = sb
                break

print(f,s)
