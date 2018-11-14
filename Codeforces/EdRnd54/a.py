import sys
n = input()
s = raw_input()
for i in xrange(n-1):
    if s[i] > s[i+1]:
        print ''.join(s[:i] + s[i+1:])
        sys.exit(0)

print s[:n-1]
