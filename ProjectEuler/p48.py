s = 0

for i in range(1,1001):
    s+= i**i

print str(s)[len(str(s))-11:]
