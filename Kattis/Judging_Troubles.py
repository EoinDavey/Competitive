n = int(raw_input())

d1 = {}
d2 = {}

for _ in range(n):
    s = raw_input()
    if s in d1:
        d1[s]+=1
    else:
        d1[s]=1

for _ in range(n):
    s = raw_input()
    if s in d2:
        d2[s]+=1
    else:
        d2[s]=1

sm = 0
for k in d1.keys():
    if k in d1 and k in d2:
        sm+=min(d1[k],d2[k])

print sm
