n = int(input())

cs = [float(x) for x in input().split()]

cbd = [x ** 3 for x in cs]
cbsum = sum(cbd)
print(pow(cbsum, 1/3))
