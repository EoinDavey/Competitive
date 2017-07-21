a = 0
b = 1
sum = 0
while(True):
    if(a > 4000000):
        break
    if a%2 == 0:
        sum+=a
    a,b = b, a+b
print sum
