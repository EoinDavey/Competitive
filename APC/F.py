x, y = [int(x) for x in input().split()]

remB = 100 - x
remA = 100 - y

totA = remB / (remA / 100)

afterT = (y/100)*totA
print(x / afterT)
