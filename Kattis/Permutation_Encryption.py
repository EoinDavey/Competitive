def fix(s,l):
    if len(s)==l:
        return s
    return "".join(list(s)+[' ']*(l-len(s)))

while(True):
    xs = map(int,raw_input().split())
    xs = xs[1:]
    n = len(xs)
    if n==0:
        break
    msg = raw_input()

    grps = [msg[i:i+n] for i in range(0,len(msg),n)]
    grps = [fix(s,n) for s in grps]

    print "'%s'"%"".join([g[i-1] for g in grps for i in xs])
