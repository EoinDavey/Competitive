n, m = map(int, raw_input().split())
xs = [input() for _ in xrange(m)]
s = set(xs)

i = 1
for j in xs:
    while i < j:
        if i not in s:
            print i
        i+=1
    print j 

while i <= n:
    if i not in s:
        print i
    i+=1
