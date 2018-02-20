N = int(input())+1

sieve = [False]*N

for i in range(3,N,2):
    if not sieve[i]:
        for j in range(i*i,N,i):
            sieve[j] = True
print(len(list(filter(lambda x: (not sieve[x]) and str(x)[0]=="1",range(3,N,2)))))
