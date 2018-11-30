n, k = map(int, raw_input().split())
s = raw_input()

o = ""
for _ in xrange(k):
    for j in xrange(n-1, -1, -1):
        if len(o) - j >= 0 and o[len(o)-j:] == s[:j]:
            o+=s[j:]
            break
print o
