import sys
reg = {}

def mod(t, i, v):
    if i == 'inc':
        reg[t] += v
    else:
        reg[t] -= v

mx = 0
for line in sys.stdin:
    l = line.strip().split()
    t = l[0]
    i = l[1]
    v = int(l[2])
    r = l[4]
    comp = l[5]
    k = int(l[6])
    if r not in reg:
        reg[r] = 0
    if t not in reg:
        reg[t] = 0
    
    if comp=='>':
        if reg[r] > k:
            mod(t, i, v)
    if comp=='>=':
        if reg[r] >= k:
            mod(t, i, v)
    if comp=='<=':
        if reg[r] <= k:
            mod(t, i, v)
    if comp=='<':
        if reg[r] < k:
            mod(t, i, v)
    if comp=='==':
        if reg[r] == k:
            mod(t, i, v)
    if comp=='!=':
        if reg[r] != k:
            mod(t, i, v)
    mx = max(mx, max(reg.items(), key=lambda (a,b): (b,a))[1])

print mx
