import sys
N = int(raw_input())
for _ in range(N):
    a = raw_input()
    b = raw_input()
    print a
    print b
    for i in xrange(len(a)):
        if a[i]==b[i]:
            sys.stdout.write('.')
        else:
            sys.stdout.write('*')
    print
    print
