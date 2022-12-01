x, y = [int(x) for x in input().split()]
r = int(input())

print("\n".join(f'{x[0]} {x[1]}' for x in [(x-r,y-r), (x-r, y+r), (x+r, y+r), (x+r, y-r)]))
