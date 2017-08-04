[W,P] = map(int,raw_input().split())

xs = map(int,raw_input().split())
xs.insert(0,0)
xs.append(W)
s=set()
for i in xs:
    for j in xs:
        if i!=j:
            s.add(abs(j-i))
l = list(s)
l.sort()
print " ".join(map(str,l))
