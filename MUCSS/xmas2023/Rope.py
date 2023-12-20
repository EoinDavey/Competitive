print('\n'.join(str(sum(1 for (a, b) in [input().split() for _ in range(int(input()))] if int(a) > int(b))) for _ in range(int(input()))))
