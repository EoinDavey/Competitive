raw_input()
a = map(int, raw_input().split())
s = set(a)
a.sort()
ln = a[-1] - a[0] + 1
print ln - len(s)
