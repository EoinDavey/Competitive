A = 1
B = 0
K = input()
for _ in xrange(K):
    A,B = B, A + B
print A, B
