n = input()
ts = [raw_input().split() for _ in range(n)]
s = set()
x = []
for (a,b) in ts:
    if a in s:
        continue
    s.add(a)
    x+=[a+" "+b]
print "\n".join(x[:12])
