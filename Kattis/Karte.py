s = raw_input()
sts = [set() for _ in range(4)]
fail = False
for c in range(0,len(s),3):
    t = s[c:c+3]
    suit = t[0]
    v = int(t[1:])
    sI = 0
    if suit=='K':
        sI=1
    if suit=='H':
        sI = 2
    if suit=='T':
        sI = 3
    if v in sts[sI]:
        fail = True
        break
    else:
        sts[sI].add(v)
if fail:
    print "GRESKA"
else:
    print " ".join(map(lambda x: str(13-len(x)),sts))
