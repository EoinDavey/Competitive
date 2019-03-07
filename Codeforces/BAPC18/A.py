n, X = map(int, raw_input().split())
xs = map(int, raw_input().split())
xs.sort()

l = []

for x in xs:
    if l and x + l[-1] > X:
        continue
    l.append(x)
print len(l)
