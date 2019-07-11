t = input()
for i in xrange(t):
    n = raw_input()
    a = ""
    b = ""
    for c in n:
        if c == '4':
            a+='3'
            b+='1'
        else:
            a+=c
            b+='0'
    print "Case #%d:" % (i+1), int(a), int(b)
