s = set()
s.add(0)
nrooms = 1

_ = input()
xs = map(int,raw_input().split())

tm = 1
for x in xs:
    if x in s:
        s.remove(x)
        s.add(tm)
    else:
        nrooms+=1
        s.add(tm)
    tm+=1

print nrooms
