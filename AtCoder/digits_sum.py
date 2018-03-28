N = list(str(input()))
mx = sum(map(lambda x: ord(x)-ord('0'),N))
for i in xrange(1,len(N)):
    N[i]='0'
N = int("".join(N))
mx = max(mx,sum(map(lambda x: ord(x)-ord('0'),str(N-1))))
print mx
