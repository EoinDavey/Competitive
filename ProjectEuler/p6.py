sumSqu = 0
sum = 0

for i in range(1,101):
    sumSqu += i**2
    sum+=i

sum = sum**2
print sum - sumSqu
