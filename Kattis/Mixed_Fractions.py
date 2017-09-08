while(True):
    [a,b] = map(int,raw_input().split())
    if a==0 and b==0:
        break
    print a/b, "%d / %d" % (a%b,b)
