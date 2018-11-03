input()
s = raw_input()
o = [s[0]]
for c in s:
    if c != o[0]:
        o.append(c)
        break
if len(o) <= 1:
    print "NO"
else:
    print "YES"
    print "".join(o)
