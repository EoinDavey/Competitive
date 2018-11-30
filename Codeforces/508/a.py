from collections import Counter
n, k = map(int, raw_input().split())
S = raw_input()
c = Counter(S)
if len(set(S)) < k:
    print 0
else:
    print c.most_common()[-1][1] * k
