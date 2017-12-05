import sys
words = reduce(lambda x,y: x+y,[line.split() for line in sys.stdin])
s = set()
for a in xrange(len(words)):
    for b in xrange(a+1,len(words)):
        s.add(words[a]+words[b])
        s.add(words[b]+words[a])
print "\n".join(sorted(list(s)))
