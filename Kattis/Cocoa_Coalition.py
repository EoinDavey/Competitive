def is_two(a, n, m):
    for i in range(1, n + 1):
        if a % i == 0 and a / i <= m:
            return True
    return False
n, m, a = *map(int, input().split()),

b = (n * m) - a

if a % n == 0 and a / n < m:
    print(1)
elif a % m == 0 and a / m < n:
    print(1)
elif is_two(a, n, m) or is_two(b, n, m):
    print(2)
else:
    print(3)
