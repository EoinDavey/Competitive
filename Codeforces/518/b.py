b = input()

cnt = 0
i = 1
while i*i <= b:
    if b%i==0:
        cnt+=2
    i+=1

if (i-1)*(i-1)==b:
    cnt-=1
print cnt
