n, m = map(int, raw_input().split())
if m > n:
    print "Dr. Chaz will have %d piece%s of chicken left over!" % (m-n, 's' if m-n != 1 else '')
else:
    print "Dr. Chaz needs %d more piece%s of chicken!" % (n-m, 's' if n-m != 1 else '')
