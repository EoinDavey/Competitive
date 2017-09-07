L = int(raw_input())
D = int(raw_input())
X = int(raw_input())

def smdig(k):
    sm = 0
    while k>0:
        sm+=k%10
        k/=10
    return sm

mx = 0
mn = 100000
for i in range(L,D+1):
    if smdig(i)==X:
        mn = min(mn,i)
        mx = max(mn,i)

print mn
print mx
