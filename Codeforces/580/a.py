import sys
def inp(): return int(input())

n = inp()
a = [int(x) for x in input().split()]
m = inp()
b = [int(x) for x in input().split()]
s = set(a + b)
for x in a:
    for y in b:
        if x + y not in s:
            print(x, y)
            sys.exit(0)
