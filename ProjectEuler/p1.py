sum = 0
for i in range(1000):
    sum+= i if i%3==0 or i%5==0 else 0
print sum
