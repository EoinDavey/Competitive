input()
l = [int(x) for x in input().split()]
print('Phew!' if all(x < y for (x, y) in zip(l,l[1:])) else 'AHH!')
