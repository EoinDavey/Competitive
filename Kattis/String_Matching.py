def buildFailure(s):
    n = len(s)
    T = [0]*(n+1)
    T[0]=-1
    j = 0
    for i in xrange(1,n):
        if s[i]==s[j]:
            T[i]=T[j]
            j+=1
        else:
            T[i] = j
            j = T[j]
            while j >= 0 and s[i]!=s[j]:
                j = T[j]
            j+=1
    T[n] = j
    return T

def search(W,S):
    N = len(S)
    T=buildFailure(W)
    p = []
    k = 0
    j = 0
    while(j < N):
        if W[k]==S[j]:
            k+=1
            j+=1
            if k==len(W):
                p.append(j-k)
                k = T[k]
        else:
            k = T[k]
            if k < 0:
                j+=1
                k+=1
    return p

while 1:
    try:
        a = raw_input()
        b = raw_input()
        print " ".join(map(str,search(a,b)))
    except EOFError:
        break
