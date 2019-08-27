for _ in range(int(input())):
    n = int(input())
    p = [int(x) - 1 for x in input().split()]
    if (all(map(lambda i: (p[i] + 1) % n == p[(i+1)%n], range(n)))
            or all(map(lambda i: p[i] == (p[(i+1)%n] + 1) % n, range(n)))):
        print("YES")
    else:
        print("NO")
