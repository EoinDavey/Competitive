N = input()
train = []
for _ in xrange(N):
    train.append(input())

def rev(x):
    return list(reversed(x))

def ind(xs,x):
    for i,b in enumerate(xs):
        if b ==x:
            return i

tgt = 1
out = []
while tgt != N+1:
    v = ind(train,tgt)
    train = train[v:] + rev(train[:v])
    if v:
        out.append(v)
    u = N - (tgt-1)
    train = train[u:] + rev(train[:u])
    if u:
        out.append(u)
    train = train[-1:] + rev(train[:-1])
    if N-1:
        out.append(N-1)
    train = train[1:] + rev(train[:1])
    out.append(1)
    u = N - (tgt)
    train = train[u:] + rev(train[:u])
    if u:
        out.append(u)
    tgt+=1
print len(out)
for i in out:
    print i
