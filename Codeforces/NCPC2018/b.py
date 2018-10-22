N = input()
xs = raw_input().split()
ind = 1
b = False
for x in xs:
    if x != "mumble" and int(x)!=ind:
        b = True
        break
    ind+=1
if b:
    print "something is fishy"
else:
    print "makes sense"
