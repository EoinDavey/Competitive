import sys
while(True):
    n = int(raw_input())
    if n==0:
        break
    n-=1
    st = format(n,'b')
    sys.stdout.write('{ ')
    b = False
    l = len(st)
    for i in range(l):
        if st[l-i-1]=='1':
            if b:
                sys.stdout.write(", ")
            sys.stdout.write(str(3**i))
            b=True
    print " }"
