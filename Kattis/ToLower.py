P, T = map(int, raw_input().split())
cnt = 0
for _ in xrange(P):
    s = [raw_input() for _ in xrange(T)]
    if all(map(lambda x: x[1:] == x[1:].lower(), s)):
        cnt+=1
print cnt
