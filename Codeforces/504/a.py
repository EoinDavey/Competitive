import sys
raw_input()
s = raw_input().split('*')
q = raw_input()
if len(s)==1:
    print "YES" if s[0]==q else "NO"
    sys.exit(0)

if sum(map(len,s)) <= len(q) and q[:len(s[0])] == s[0] and q[len(q)-len(s[1]):]==s[1]:
    print "YES"
else:
    print "NO"

