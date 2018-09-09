s = set()
pv = ""

fail = False
N = input()
for _ in xrange(N):
    w = raw_input()
    if w in s or (pv and w[0] != pv[len(pv)-1]):
        fail=True
        break
    s.add(w)
    pv = w
if fail:
    print "No"
else:
    print "Yes"
