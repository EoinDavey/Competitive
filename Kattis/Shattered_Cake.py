W = input()
N = input()
a = 0
for _ in xrange(N):
    w,l = map(int,raw_input().split())
    a+=w*l
print a/W
