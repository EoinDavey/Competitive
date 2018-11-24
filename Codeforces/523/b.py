n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
tot = sum(a)
a = map(lambda x: x- 1, a)
keep = n + max(a)
print tot-keep
