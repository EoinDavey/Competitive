MX_N = 500005
MOD7 = 10**9 + 7

qcnt = [0]*MX_N
ocnt = [0]*MX_N

sin = raw_input()
N = len(sin)
qcnt[0] = 1 if sin[0]=='?' else 0
ocnt[0] = 1 if sin[0]=='1' else 0

for i in range(1,N):
    qcnt[i] = qcnt[i-1] + (1 if sin[i]=='?' else 0)
    ocnt[i] = ocnt[i-1] + (1 if sin[i]=='1' else 0)

k = qcnt[N-1]
xk = pow(2,k,MOD7)
xk_1 = 0 if k < 1 else pow(2,k-1,MOD7)
xk_2 = 0 if k <= 1 else pow(2,k-2,MOD7)

out = 0

for i in range(N):
    if sin[i]=='0':
        out += ocnt[i]
        out %= MOD7

out *= xk
out %= MOD7

for i in range(N):
    if sin[i]=='0':
        out += (qcnt[i] * xk_1)
        out %= MOD7
    elif sin[i]=='1':
        out += ((k-qcnt[i]) * xk_1)
        out %= MOD7

nPairs = (k*(k-1))/2

out += nPairs * xk_2
out %= MOD7

print out
