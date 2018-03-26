import sys
mp = {}
for line in sys.stdin:
    coms = line.split()
    if coms[0]=="define":
        i = int(coms[1])
        x = coms[2]
        mp[x]=i
    elif coms[0]=="eval":
        x = coms[1]
        z = coms[2]
        y = coms[3]
        if x not in mp or y not in mp:
            print "undefined"
        elif z=="<":
            print "true" if mp[x] < mp[y] else "false"
        elif z==">":
            print "true" if mp[x] > mp[y] else "false"
        elif z=="=":
            print "true" if mp[x] == mp[y] else "false"
