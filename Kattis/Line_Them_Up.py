N = input()
names = [raw_input() for _ in range(N)]
aSort = sorted(names)
rSort = aSort[::-1]

if all(map(lambda x: names[x]==aSort[x],range(N))):
    print "INCREASING"
elif all(map(lambda x: names[x]==rSort[x],range(N))):
    print "DECREASING"
else:
    print "NEITHER"
