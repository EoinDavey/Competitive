N = input()
S = raw_input()
lcnt = [0]*N
rcnt = [0]*N
run = 0
for i,c in enumerate(S):
    lcnt[i] = run
    run+=c=='W'
run=0
for i,c in enumerate(reversed(S)):
    rcnt[N-i-1] = run
    run+=c=='E'

print min(map(lambda i:lcnt[i]+rcnt[i],range(N)))
