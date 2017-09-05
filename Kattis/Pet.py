vs = []
for _ in range(5):
    s = 0
    xs = map(int,raw_input().split())
    for i in range(4):
        s+=xs[i]
    vs.append(s)
    
m = max(vs)
for i in range(5):
    if vs[i]==m:
        print i+1, m
        break
