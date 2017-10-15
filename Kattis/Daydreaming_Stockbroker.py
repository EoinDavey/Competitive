d = input()
pcs = [input() for _ in range(d)]

money = 100 
for i in xrange(d-1):
    if pcs[i+1] > pcs[i]:
        money += min(money/pcs[i],100000)*(pcs[i+1]-pcs[i])
print money
