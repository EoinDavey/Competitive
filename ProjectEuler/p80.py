import math

def sqrt(x):
    s = str(x)
    if len(s)%2!=0:
        s = '0'+s
    rem = 0
    p = 0
    i = 0
    while(1):
        rem*=100
        c = rem + (int(s[i:i+2]) if i+2 <= len(s) else 0)
        x = 9
        while (20 * p + x)*x > c:
            x-=1
        y = x*(20*p + x)
        yield x
        p = 10*p + x
        rem = c - y
        if rem == 0:
            break
        i+=2

def digsum(x):
    sm = 0
    s = sqrt(x)
    for _ in range(100):
        sm+=next(s)
    return sm

sm = 0
for i in range(1,101):
    if int(math.sqrt(i))**2 == i:
        continue
    sm+=digsum(i)
print sm
