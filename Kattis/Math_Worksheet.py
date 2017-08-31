N = 0

def line(vals,mxlen):
    s = map(str,vals)
    out = ""
    for i,l in enumerate(s):
        for _ in range(len(l),mxlen):
            out+=" "
        out += l
        if i!= len(s)-1:
            out+=" "
    return out

def check(vals,colN,mxLen):
    for v in range(0,N,colN):
        l = line(vals[v:min(N,v+colN)],mxLen)
        if len(l) > 50:
            return False
    return True

def build(vals,colN,mxlen):
    lines = []
    for v in range(0,N,colN):
        lines.append(line(vals[v:min(N,v+colN)],mxlen))
    return '\n'.join(lines)

fst=True
while(True):
    N = int(raw_input())
    if N==0:
        break
    if not fst:
        print
    vals = []
    for _ in range(N):
        vals.append(eval(raw_input()))
    colLen = 1
    mxLen = max(map(lambda x: len(str(x)),vals))
    for _ in range(N):
        if not check(vals,colLen,mxLen):
            break
        colLen+=1
    print build(vals,colLen-1,mxLen)
    fst=False
