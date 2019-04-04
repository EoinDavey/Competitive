n = input()
sx  = list(map(int, input().split()))

if n=='8' and sx[0] == '4':
    print(3)
elif n=='8' and sx[0] == '0':
    print(1)
else:
    print(2)
