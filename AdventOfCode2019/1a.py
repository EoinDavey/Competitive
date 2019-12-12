import sys

sm = 0
for line in sys.stdin:
    sm += int(line) // 3 - 2
print(sm)
