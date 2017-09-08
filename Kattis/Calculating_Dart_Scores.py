scores = range(1,21)
singles = zip(["single"]*20,scores,scores)
doubles = zip(["double"]*20,map(lambda x: 2*x,scores),scores)
triples = zip(["triple"]*20,map(lambda x: 3*x,scores),scores)
a = [("",0,0)] + singles+doubles+triples
N = len(a)

target = int(raw_input())

suc = False

for i in range(N):
    if suc:
        break
    for j in range(i,N):
        if suc:
            break
        for k in range(j, N):
            if suc:
                break
            if a[i][1] + a[j][1] + a[k][1] == target:
                if a[i][2] != 0:
                    print a[i][0], a[i][2]
                if a[j][2] != 0:
                    print a[j][0], a[j][2]
                if a[k][2] != 0:
                    print a[k][0], a[k][2]
                suc = True
if not suc:
    print "impossible"
