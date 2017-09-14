K = int(raw_input())-1
N = int(raw_input())

lm = 3*60 + 30

tm = 0
for _ in range(N):
    [n,t] = raw_input().split()
    n = int(n)
    tm+=n
    if tm >= lm:
        break
    if t=='T':
        K = (K+1) % 8
print K+1
