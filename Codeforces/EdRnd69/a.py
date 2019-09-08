for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    print(min(a[-1] - 1, a[-2] - 1, n - 2))
