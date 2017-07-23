def pent():
    n = 1
    while(1):
        yield(n*(3*n-1)/2)
        n+=1

p = pent()

s = set()
sm = set()

x = 0
while(True):
    n = next(p)
    if n in sm:
        x = n
        break
    for a in s:
        d = n-a
        if d in s:
            sm.add(n+a)
    s.add(n)

for a in s:
    for b in s:
        if a+b == x:
            print a-b
