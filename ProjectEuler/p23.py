import math
abundant = []
for x in range(1,28124):
    t = 0
    for y in range(1,int(math.sqrt(x))+1):
        if x % y == 0:
            t+=y+(x/y)
    t-=x
    if int(math.sqrt(x))**2==x:
        t-=int(math.sqrt(x))
    if t > x:
        abundant.append(x)

s = [x for x in range(28124)]
n = len(abundant)
for i in range(n):
    for j in range(i,n):
        x = abundant[i]
        y = abundant[j]
        if x + y < 28124:
            s[x+y] =  0

print s[:25]
print sum(s)
