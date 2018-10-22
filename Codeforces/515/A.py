t = input()
for _ in xrange(t):
    L, v, l, r = map(int, raw_input().split())
    print L/v - r/v + (l-1)/v
