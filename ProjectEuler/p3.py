a = 600851475143

i = 2
while(a!=1):
    while(a%i==0):
        a/=i
        print i
    i+=1
