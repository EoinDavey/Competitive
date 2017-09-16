fst = True
while(True):
    try:
        N = int(raw_input())
    except(EOFError):
        break
    if not fst:
        print
    fst = False
    d = {}
    while(1):
        s = raw_input()
        if s=="EndOfText":
            break
        w = []
        for c in s:
            if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'):
                w.append(c)
            else:
                if len(w) > 0:
                    s = "".join(w).lower()
                    if s in d:
                        d[s]+=1
                    else:
                        d[s]=1
                w = []
        if len(w) > 0:
            s = "".join(w).lower()
            if s in d:
                d[s]+=1
            else:
                d[s]=1
    l = []
    for (w,f) in d.iteritems():
        if f==N:
            l.append(w)
    l.sort()
    for w in l:
        print w
    if len(l) ==0:
        print "There is no such word."
