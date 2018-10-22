def pad(s, m):
    if len(s) == m:
        return s
    return "".join(['0']*(m-len(s))) + s
n, m = map(int, raw_input().split())
N = max(n,m)
a = pad(raw_input(), N)
b = pad(raw_input(), N)

MD = 998244353

lCount = [0]*N
lCount[0] = 1 if b[0]=='1' else 0

pows = [1]*N
for i in xrange(1,N):
    pows[i] = (pows[i-1]*2)%MD

for i in xrange(1, N):
    lCount[i] = lCount[i-1] + (1 if b[i] =='1' else 0)

tot = 0
for i in xrange(N):
    if a[i]=='1':
        tot = (tot + ((lCount[i] * pows[N-i-1])%MD))%MD
print tot
