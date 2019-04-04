s = raw_input()
sm = 0
for i in xrange( len(s)):
    if s[i]==s[(i+1)%len(s)]:
        sm += int(s[i])
print sm
