import sys
n, k = map(int, raw_input().split())
lim = (k-1)/2

if k - lim > n:
    print "0"
    sys.exit(0)

print min(lim, n-(k-lim)+1)
