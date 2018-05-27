N,K,Q = map(int,raw_input().split())

As = map(int,raw_input().split())

Sas = sorted(As)

def pos(x):
    pass


mn = 4*1000*1000*1000
for i,a in enumerate(Sas):
    if pos(a):
        mn = min(mn,Sas[i+Q-1]-a)
