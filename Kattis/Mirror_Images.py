import sys
T = int(raw_input())
for t in range(T):
    [R,C] = map(int,raw_input().split())
    ls = [raw_input() for _ in range(R)]
    print "Test %d" % (t+1)
    for i in range(R)[::-1]:
        print ls[i][::-1]
