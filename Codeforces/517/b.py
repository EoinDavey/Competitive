n = input()
a = map(int, raw_input().split())
b = map(int, raw_input().split())
succ = False
for last in xrange(4):
    t = [last]
    for i in xrange(len(a)):
        fail = True
        for x in xrange(4):
            if a[i] == x | t[-1] and b[i] == x & t[-1]:
                t.append(x)
                fail = False
                break
        if fail:
            break
    if len(t)==n:
        print "YES"
        print " ".join(map(str,t))
        succ=True
        break
if not succ:
    print "NO"
