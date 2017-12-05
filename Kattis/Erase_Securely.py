N = input()
s1 = raw_input()
s2 = raw_input()
if N%2==0:
    if s1 == s2:
        print "Deletion succeeded"
    else:
        print "Deletion failed"
else:
    ns = "".join(map(lambda c: ["1","0"][c=='1'],s1))
    if s2==ns:
        print "Deletion succeeded"
    else:
        print "Deletion failed"
