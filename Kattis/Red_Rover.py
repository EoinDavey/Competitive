import re
S = raw_input()
mnl = len(S)
l = len(S)

for i in xrange(l):
    for j in xrange(i,l):
        sb = S[i:j+1]
        mnl = min(mnl,len(re.sub(sb,'M',S))+len(sb))

print mnl
