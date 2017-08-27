N = int(raw_input())

sm = 0
for _ in xrange(N):
    s = raw_input()
    sm+=int(s[:-1])**int(s[len(s)-1])
print sm
