m, n = *map(int,input().split()),
p = {i: i for i in range(n)}
def find(x):
    p[x] = x if x == p[x] else find(p[x])
    return p[x]
def join(a, b):
    p[find(a)] = find(b)

for _ in range(m):
    cm = input().split()
    x, y = *map(int, cm[1:]),
    if cm[0] == 'Q':
        print("ftarlusee"[find(x)==find(y)::2])
    else:
        join(x,y)
