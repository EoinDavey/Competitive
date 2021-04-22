import sys

sm = 0
for line in sys.stdin:
    x = int(line) // 3 - 2
    while x > 0:
        sm += x
        x = x // 3 - 2
print(sm)
