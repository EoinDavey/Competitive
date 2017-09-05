[a,b] = raw_input().split()
a = a[::-1]
b = b[::-1]
if int(a) > int(b):
    print a
else:
    print b
