[n,k] = [int(x) for x in raw_input().split()]
a = [float(x) for x in raw_input().split()]

sumT = 0.0
prev = 0.0
for i in range(0,n):
    prev+=a[i]
    if i >= k-1:
        sumT+=prev
        prev-= a[i-k+1]


print "%.7f" % (float(sumT) / (n-k+1))
