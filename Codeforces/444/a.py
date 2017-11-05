zcnt = 0
ocnt = 0

inp = raw_input()
oind=0
for i in xrange(len(inp)):
    if inp[i]=='1':
        oind=i
        break

for c in inp[oind:]:
    zcnt+= c=='0'
    ocnt+= c=='1'

if zcnt >= 6 and ocnt > 0:
    print "yes"
else:
    print "no"
