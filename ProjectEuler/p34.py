N = 2500000
def f(i):
    if i <= 1:
        return 1
    return i*f(i-1)

fac = [f(i) for i in range(10)]

def check(x):
    s = 0
    for n in str(x):
        s+= fac[ord(n)-ord('0')]
    return s==x

s = 0
for i in range(3,N):
    if check(i):
        s+=i
print s
