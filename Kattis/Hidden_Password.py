[p,s] = raw_input().split()

fail = False
for c in s:
    if c in p:
        if c!=p[0]:
            fail = True
            break
        p = p[1:]
if len(p) > 0:
    fail = True
if fail:
    print "FAIL"
else:
    print "PASS"
