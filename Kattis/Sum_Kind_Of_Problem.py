print "\n".join(map(lambda xs: str(xs[0]) + " " + str((xs[1]*(xs[1]+1)/2)) + " " + str(xs[1]**2) +  " " + str(xs[1]**2 + xs[1]),[map(int,raw_input().split()) for _ in xrange(input())]))
