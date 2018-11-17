import sys
n, m, k = map(int, raw_input().split())

if ((k-2)*n*m) % k != 0:
    print "NO"
    sys.exit(0)

bc = ((k-2)*n*m)/k
print bc
