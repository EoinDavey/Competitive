T = int(input())
for _ in range(T):
    N = int(input())
    ls = [int(x) for x in input().split()]
    print("Player %d wins" % ls[-1])
