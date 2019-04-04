import sys
s = 0
for line in sys.stdin:
    a = map(int, line.strip().split())
    for i in xrange(len(a)):
        for j in xrange(i+1, len(a)):
            if a[i]%a[j] == 0:
                s+=a[i]/a[j]
            elif a[j]%a[i] == 0:
                s+=a[j]/a[i]
print s
