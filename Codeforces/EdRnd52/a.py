for _ in xrange(input()):
    s, a, b, c = map(int, raw_input().split())
    sm = 0
    sm+= (s/(c*a))*(a+b)
    s %= c*a
    sm += s/c
    print sm
