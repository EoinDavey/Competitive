N = input()
ls = range(1,N+1)
while len(ls) > 3:
    nls = ls[1::2]
    for i in xrange(len(ls) - len(nls)):
        print ls[0],
    ls = nls
if len(ls)==3:
    print ls[0], ls[0], ls[2]
elif len(ls)==2:
    print ls[0], ls[1]
else:
    print ls[0]
