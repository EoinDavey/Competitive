lim = 2**32 - 1
up = 65535

ps = [set() for _ in range(33)]

def check(x):
    for i in range(1,33)[::-1]:
        if x in ps[i]:
            return i
    return 1

for i in range(2,up+1):
    j = 0
    while(i**j<=lim):
        ps[j].add(i**j)
        j+=1

for i in range(2,up+1):
    i*=-1
    j = 1
    while(i**j>=-lim):
        ps[j].add(i**j)
        j+=2

while(True):
    n = int(raw_input())
    if(n==0):
        break
    print check(n)
