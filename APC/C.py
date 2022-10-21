import heapq
from collections import defaultdict

n = int(input())

def expert_time(steps):
    done = set()
    cando = []
    inProg = []

    dependsOn = defaultdict(list)
    pending = defaultdict(int)
    for (name, (t, ds)) in steps.items():
        for x in ds:
            dependsOn[x].append(name)
            pending[name] += 1

    for (name, (t, ds)) in steps.items():
        if len(ds) == 0:
            heapq.heappush(inProg, (t, name))

    t = 0
    while len(inProg) > 0:
        #print(f'time t={t}')
        #print(f'inProg={inProg}')

        (t, dun) = heapq.heappop(inProg)
        #print(f'{dun} is done')
        for x in dependsOn[dun]:
            #print(f'subtracting one from {x}')
            pending[x] -= 1
            if pending[x] == 0:
                dt = steps[x][0]
                heapq.heappush(inProg, (t + dt, x))

    return t

def solve(rname, steps):
    ep = expert_time(steps)
    bt = sum(t for (t, _) in steps.values())
    return bt/ep

ls = []
for _ in range(n):
    name, s = input().split()
    s = int(s)
    steps = {}
    for _ in range(s):
        l = input().split()
        sn = l[0]
        t = int(l[1])
        ds = l[3:]
        steps[sn] = (t, ds)
    ls.append((solve(name, steps), name))

ls.sort()

for (_, n) in ls:
    print(n)
