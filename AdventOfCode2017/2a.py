s = 0
for line in sys.stdin:
    a = map(int, line.strip().split())
    s += max(a) - min(a)

print s
