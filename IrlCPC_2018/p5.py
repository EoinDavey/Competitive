a = [0 for _ in range(0)]
sets = [set() for _ in range(100)]

N = int(input())
a = list(map(int,input().split()))
sets[0].add(0);
for i in range(N):
    sets[1<<i].add(a[i]);
survive = True
while(survive):
        survive = False;
        for i in range(1<<N):
            for j in range(1<<N):
                    if((i&j) > 0):#non-disjoint
                            continue;
                    ns = i | j;
                    nset = set()
                    for a in sets[i]:
                        for b in sets[j]:
                                if(a+b not in sets[ns]):
                                        nset.add(a+b);
                                        survive = True;
                                if(a >= b and a-b not in sets[ns]):
                                        nset.add(a-b);
                                        survive = True;
                                if(a*b not in sets[ns]):
                                        nset.add(a*b);
                                        survive = True;
                                if(b!= 0 and a%b==0 and a//b not in sets[ns]):
                                        nset.add(a//b);
                                        survive = True;
                    sets[ns] = sets[ns].union(nset)

a = set()
for i in range(1<<N):
    for b in sets[i]:
        a.add(b)
ans = 1;
while True:
    if ans not in a:
        break
    ans +=1
print(ans)
