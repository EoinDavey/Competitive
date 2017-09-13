def won(m1,m2):
    if m1=='rock'and m2=='scissors':
        return True
    if m1=='paper' and m2=='rock':
        return True
    if m1=='scissors' and m2=='paper':
        return True
    return False

while(True):
    s = raw_input()
    if s=='0':
        break
    [n,k] = map(int,s.split())
    wn = {}
    ls = {}
    for i in range(1,n+1):
        wn[i]=ls[i] = 0
    for _ in range((k*n*(n-1))/2):
        [p1,m1,p2,m2] = raw_input().split()
        p1 = int(p1)
        p2 = int(p2)
        if won(m1,m2):
            wn[p1]+=1
            ls[p2]+=1
        if won(m2,m1):
            wn[p2]+=1
            ls[p1]+=1
    for i in range(1,n+1):
        if wn[i]+ls[i] > 0:
            print "%.3f" % ((wn[i]*1.0)/(wn[i]+ls[i]))
        else:
            print "-"
    print
