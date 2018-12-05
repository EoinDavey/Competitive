import sys
s = "0"
for line in sys.stdin:
    s+=line[:-1]
    print "read", line

print s
print eval(s)
