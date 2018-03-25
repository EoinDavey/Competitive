fin = open("sort.in","r")
fout = open("sort.out","w+")
N = int(fin.readline())
A = [int(fin.readline()) for _ in xrange(N)]
sA = sorted(A)
pos = {}
cnt = {}
for i,x in enumerate(sA):
    if x not in pos:
        pos[x] = i

mx = 0
for i,x in enumerate(A):
    finalPos = pos[x] + (cnt[x] if x in cnt else 0)
    if x in cnt:
        cnt[x]+=1
    else:
        cnt[x] = 1
    dist = i - finalPos
    mx = max(mx,dist)

fout.write(str(mx+1)+"\n")

fin.close()
fout.close()
