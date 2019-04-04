import sys
gph = {
}

for line in sys.stdin:
    l = line.strip().split()
    a = int(l[0])
    if a not in gph:
        gph[a] = []
    for b in l[2:]:
        x = int(b[:-1]) if b[-1]==',' else int(b)
        if x not in gph:
            gph[x] = []

        gph[x].append(a)
        gph[a].append(x)

vis = set()
cnt = 0
def dfs(x):
    global cnt
    if x in vis:
        return
    cnt+=1
    vis.add(x)
    for v in gph[x]:
        dfs(v)

tot = 0
for i in gph:
    if i not in vis:
        dfs(i)
        tot+=1
print cnt
print tot
