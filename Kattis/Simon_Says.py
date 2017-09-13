N = int(raw_input())
for _ in xrange(N):
    s = raw_input()
    if s[:10] == "Simon says":
        print s[11:]
