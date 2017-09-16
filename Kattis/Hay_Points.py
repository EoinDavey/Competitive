[N,M] = map(int,raw_input().split())
d = {}
for _ in range(N):
    [s,n] = raw_input().split()
    d[s] = int(n)

for _ in range(M):
    sm = 0
    while(True):
        s = raw_input()
        if s=='.':
            break
        for c in s.split():
            if c in d:
                sm+= d[c]
    print sm
