a,b = map(int, raw_input().split())

ao = []
bo = []

sm = 0
i = 1
maxS = 0
while 1:
    if sm + i > a + b:
        break
    sm += i
    maxS = i
    i+=1

for j in xrange(maxS, 0, -1):
    if a > b:
        a -= j
        ao.append(j)
    else:
        b-=j
        bo.append(j)


print len(ao)
print " ".join(map(str, ao))
print len(bo)
print " ".join(map(str, bo))
