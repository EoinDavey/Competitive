N = input()
N+=2
sq = [1]*N

for x in xrange(1,N):
    sq[x] = (2*x*(2*x-1)*sq[x-1])/((x+1)*x)

print sq[N-1]
