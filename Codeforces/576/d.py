import sys
 
in_file = sys.stdin
 
n = int(in_file.readline().strip())
a = list(map(int, in_file.readline().strip().split()))
q = int(in_file.readline().strip())
ls = [list(map(int, in_file.readline().strip().split())) for _ in range(q)]

mxs = [-1]*q
mxs[-1] = ls[-1][1] if ls[-1][0] == 2 else -1 

for i in range(q-2, -1, -1):
    mxs[i] = max(mxs[i+1], ls[i][1] if ls[i][0] == 2 else -1)

o = [max(mxs[0], x) for x in a]
for i in range(q):
    if ls[i][0] != 1:
        continue
    p, x = ls[i][1:]
    o[p-1] = max(x, mxs[i])

sys.stdout.write(" ".join(map(str, o)))
sys.stdout.flush()
