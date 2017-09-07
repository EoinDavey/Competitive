[a,b,c] = map(int,raw_input().split())

if a+b==c:
    print "%d+%d=%d" % (a,b,c)
elif a-b==c:
    print "%d-%d=%d" % (a,b,c)
elif a*b==c:
    print "%d*%d=%d" % (a,b,c)
elif a%b==0 and a/b==c:
    print "%d/%d=%d" % (a,b,c)
elif a==b+c:
    print "%d=%d+%d" % (a,b,c)
elif a==b-c:
    print "%d=%d-%d" % (a,b,c)
elif a==b*c:
    print "%d=%d*%d" % (a,b,c)
elif b%c==0 and a==b/c:
    print "%d=%d/%d" % (a,b,c)
