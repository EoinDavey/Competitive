fin = open('milkorder.in','r')
fout = open('milkorder.out','w+')
N,M,K = map(int,fin.readline().split())
ms = map(int,fin.readline().split())
ks = [map(int,fin.readline().split()) for _ in range(K)]

def checkInd(i):
    inserted = set()
    cows = [0]*(N+1)
    cows[i] = 1
    inserted.add(1)
    for a,b in ks:
        if cows[b] != 0 or a in inserted:
            return False
        cows[b] = a
        inserted.add(a)
    rind = 1
    for x in ms:
        if rind > N:
            return False
        if x in inserted:
            while cows[rind] != x:
                rind+=1
                if rind > N:
                    return False
            rind+=1
        else:
            while cows[rind]!=0:
                rind+=1
                if rind > N:
                    return False
            cows[rind] = x
            rind+=1
    return True

for a,b in ks:
    if a==1:
        fout.write(str(b)+"\n")
        break
# 1 not in ks
if not any(map(lambda x:x[0]==1,ks)):
    for i in xrange(1,N+1):
        if checkInd(i):
            fout.write(str(i)+"\n")
            break

fin.close()
fout.close()
