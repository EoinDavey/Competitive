for t in xrange(input()):
    n = input()
    p = raw_input()
    ans = map(lambda x: 'E' if x=='S' else 'S', p)
    print "Case #%d:" % (t+1), ''.join(ans)
