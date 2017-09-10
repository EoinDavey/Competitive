S = raw_input()
white = low = up = sym = 0

lower = map(chr,range(ord('a'),ord('z')+1))
upper = map(chr,range(ord('A'),ord('Z')+1))

for c in S:
    if c=='_':
        white+=1
    elif c in lower:
        low+=1
    elif c in upper:
        up+=1
    else:
        sym+=1
n = len(S)
print "%.8f" % ((white*1.0)/n)
print "%.8f" % ((low*1.0)/n)
print "%.8f" % ((up*1.0)/n)
print "%.8f" % ((sym*1.0)/n)
