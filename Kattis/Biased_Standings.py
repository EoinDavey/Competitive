def gen():
    l = raw_input().split()
    return int(l[1])

T = int(raw_input())

for _ in range(T):
    raw_input()
    N = int(raw_input())

    pos = [gen() for _ in range(N)]

    pos.sort()

    cost = 0
    for i,v in enumerate(pos):
        cost+=abs(v-(i+1))

    print cost
