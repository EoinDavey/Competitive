N = input()
adjMat = [map(int,raw_input().split()) for _ in xrange(N)]
s1 = set()

for i in xrange(N):
    fail = False
    for s in s1:
        if adjMat[i][s] == 1:
            fail = True
            break
    if not fail:
        s1.add(i)

s2 = set(range(N)).difference(s1)
print " ".join(map(str,sorted(list(s1))))
print " ".join(map(str,sorted(list(s2))))
