import sys
def err():
    print("Error")
    sys.exit(0)

c, h, o = *map(int, input().split()),
if (2*o-h)%4:
    err()

y = (2*o-h)//4

if (c-y)%6:
    err()

z = (c-y)//6

if (h-12*z)%2:
    err()

x = (h-12*z)//2

if 2*x + 12*z != h or y + 6*z != c or x + 2*y + 6*z != o:
    err()

print(x,y,z)
